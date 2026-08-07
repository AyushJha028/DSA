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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        //if(root)
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(! q.empty()){
            int n=q.size();
            double sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                sum += curr->val;
                q.pop();
                if(i==n-1)
                    ans.push_back(sum/n);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
           // ans.push_back(sum/level);
            level++;
        }
        return ans;
    }
};