class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums,vector<int>& path,int i){
        if(i >= nums.size()){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        solve(nums,path,i+1);
        path.pop_back();

        solve(nums,path,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        solve(nums,path,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};