/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA, *q=headB;
        int countA=0, countB=0;
        while(p){
            countA++;
            p=p->next;
        }
        while(q){
            countB++;
            q=q->next;
        }
        if(countA>=countB){
            p=headA;
            q=headB;
        }else{
            p=headB;
            q=headA;
        }
        int diff=(countA>=countB) ? countA-countB : countB-countA;
        while(diff--){
            p=p->next;
        }
        while(p&&q){
            if(p==q) return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};