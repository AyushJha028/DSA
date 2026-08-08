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
    TreeNode* prev =NULL;
    bool isValid=true;
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        dfs(root->left);
        if(prev != NULL){
            if(prev->val >= root->val)
                isValid=false;
        }
        prev = root;
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return isValid;
    }
};