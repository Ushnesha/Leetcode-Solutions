/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertInSorted(ListNode* head, ListNode* node){
        if(node->val<=head->val){
            node->next=head;
            head=node;
        }else{
            ListNode* p=NULL, *q=head;
            while(q && q->val<node->val){
                p=q;
                q=q->next;
            }
            p->next=node;
            node->next=q;
        }
        return head;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* sorted=head, *cur=head->next;
        sorted->next=NULL;
        while(cur){
            ListNode* next=cur->next;
            sorted=insertInSorted(sorted, cur);
            cur=next;
        }
        return sorted;
    }
};