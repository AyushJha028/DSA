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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(l1 != NULL || l2!= NULL || carry != 0){
            int digit1=0,digit2=0;
            if(l1 != nullptr)
                digit1=l1->val;
            if(l2 != nullptr)
                digit2 = l2->val;
            int sum=digit1 + digit2 + carry;
            int digit = sum %10;
            carry = sum /10;

            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp= temp->next;

            l1 = (l1!=NULL) ? l1->next : nullptr;
            l2 = (l2!= NULL) ? l2->next : nullptr;
        }
        ListNode* ans=head->next;
        delete head;
        return ans;
    }
};