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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        int length=0;
        while(fast != NULL){
            length++;
            fast=fast->next;
        }
        if(length == n)
            return head->next;
        ListNode* temp=head;
        ListNode* prev=NULL;
        for(int i=0;i<length-n;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete(temp);
        return head;
    }
};