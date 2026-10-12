class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& candidates, int target,vector<int>& temp,int idx ){
      
            if(target == 0){
                ans.push_back(temp);
                return;
            }

              if(idx == n){
                return;
              }

        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            solve(candidates,target - candidates[idx],temp,idx);
            temp.pop_back();
        }
        solve(candidates,target,temp,idx+1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int> temp;
        solve(candidates,target,temp,0);
        return ans;
    }
};