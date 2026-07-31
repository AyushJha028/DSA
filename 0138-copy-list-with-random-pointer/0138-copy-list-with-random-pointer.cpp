/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    0
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        unordered_map<Node*,Node*> mpp;
        Node* curr=head;
        Node* prev=NULL;
        Node* newhead= NULL;
        while(curr != NULL){
            Node* temp = new Node(curr->val);
            mpp[curr] = temp;
            if(newhead==NULL){
                newhead=temp;
                prev=newhead;
            }
            else{
                prev->next = temp;
                prev=temp;
            }
            curr=curr->next;
        }
        curr=head;
        Node* newCurr=newhead;
        while(curr){
            if(curr->random == NULL){
                newCurr->random =NULL;
            }
            else{
                newCurr->random = mpp[curr->random];
            }
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newhead;
    }
};