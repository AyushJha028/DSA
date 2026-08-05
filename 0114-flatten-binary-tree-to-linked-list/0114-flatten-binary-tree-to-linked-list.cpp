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
    void dfs(TreeNode* root,vector<int>& nums){
        if(root == NULL)
            return ;
        nums.push_back(root->val);
        dfs(root->left,nums);
        dfs(root->right,nums);
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        vector<int> nums;
        dfs(root,nums);
        TreeNode* curr=root;
        for(int i=1;i<nums.size();i++){
            TreeNode* temp=new TreeNode(nums[i]);
            curr->left=NULL;
            curr->right=temp;
            curr=curr->right;
        }
        curr->right = NULL;
    }
};