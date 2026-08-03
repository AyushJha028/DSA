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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== NULL || head->next == NULL || k==0)
            return head;
        int n=1;
        ListNode* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0)
            return head;
        temp->next=head;
        ListNode* curr=head;
        ListNode* newhead=NULL;
        for(int i=1;i<n-k;i++){
            curr=curr->next;
        }
        newhead=curr->next;
        curr->next=NULL;
        return newhead;
    }
};