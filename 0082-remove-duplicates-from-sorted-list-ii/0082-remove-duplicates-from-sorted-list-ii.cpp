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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* dumm=new ListNode(0);
        ListNode* curr=dumm;

        while(temp!= NULL){
            if(temp->next ==NULL || temp->val != temp->next->val){
                curr->next=temp;
                curr=curr->next;
                temp=temp->next;
            }
            else{
                int dup=temp->val;
                while(temp != NULL  && temp->val == dup){
                    temp=temp->next;
                }
            }
        }
        curr->next =NULL;
        return dumm->next;
    }
};