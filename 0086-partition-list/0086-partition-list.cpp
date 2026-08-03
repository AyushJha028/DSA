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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* less=new ListNode(0);
        ListNode* lp=less;
        ListNode* great=new ListNode(0);
        ListNode* gp=great;
        while(temp != NULL){
            if(temp->val <x){
                lp->next=temp;
                lp=lp->next;
            }
            else{
                gp->next=temp;
                gp=gp->next;
            }
            temp=temp->next;
        }
        gp->next=NULL;
        lp->next=great->next;
        return less->next;
    }
};