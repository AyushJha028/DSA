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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL; 
        return temp;
    }
    ListNode* getKthNode(ListNode* temp,int k){
        k--;
        while(temp != NULL && k >0){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(temp != NULL){
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode == NULL){
                if(prev){
                    prev->next =temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prev->next = kthNode;
            }
            
            prev = temp;
            temp = nextNode;

        }
        return head;
    }
};