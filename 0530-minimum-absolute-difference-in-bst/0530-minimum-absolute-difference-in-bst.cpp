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
    vector<int>temp;
    void dfs(TreeNode* root){
        if(root == nullptr)
            return ;
        int d=root->val;
        temp.push_back(d);
        dfs(root->left);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
       dfs(root);
       sort(temp.begin(),temp.end());
       int ans=INT_MAX;
       int n=temp.size();
       for(int i=0;i<n-1;i++){
            ans=min(ans,temp[i+1]-temp[i]);
       } 
       return ans;
    }
};