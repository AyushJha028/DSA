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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> temp;
        ListNode* fast=head;
        while(fast!=NULL){
            int d=fast->val;
            fast=fast->next;
            temp.push_back(d);
        }
        while(left<right){
            swap(temp[left-1],temp[right-1]);
            left++;
            right--;
        }
        ListNode* ans= new ListNode(temp[0]);
        ListNode* curr=ans;
        for(int i=1;i<temp.size();i++){
            curr->next = new ListNode(temp[i]);
            curr = curr->next;
        }
        return ans;
    }
};