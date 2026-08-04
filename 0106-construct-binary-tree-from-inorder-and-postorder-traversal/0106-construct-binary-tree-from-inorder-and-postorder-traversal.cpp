/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* building(vector<int>& inorder, vector<int>& postorder,int start,int end,int &idx){
        if(start > end)
            return NULL;
        int rootVal=postorder[idx];
        idx--;
        int i=start;
        for(;i<end;i++){
            if( rootVal == inorder[i])
                break;
        }
        TreeNode* root=new TreeNode(rootVal);
        root->right = building(inorder,postorder,i+1,end,idx);
        root->left = building(inorder,postorder,start,i-1,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;
        return building(inorder,postorder,0,n-1,idx);
    }
};