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
    ListNode* SecondHalf(ListNode* head){
        ListNode* p=head;
        ListNode* q=head->next;
        while(q && q->next){
            p=p->next;
            q=q->next->next;
        }
        q=p->next;
        p->next=NULL;
        return q;
    }
    ListNode* MergeSort(ListNode* a, ListNode* b){
        ListNode* res=NULL;
        if(a==NULL) return b;
        if(b==NULL) return a;
        if(a->val<=b->val){
            res=a;
            res->next=MergeSort(a->next, b);
        }else{
            res=b;
            res->next=MergeSort(a,b->next);
        }
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=head;
        ListNode* b=SecondHalf(head);
        a=sortList(a);
        b=sortList(b);
        return MergeSort(a,b);
    }
};