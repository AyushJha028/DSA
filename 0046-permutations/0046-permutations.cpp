class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    int n;
    void solve(vector<int>& poss,vector<int>& nums){
        if(poss.size() == n){
            ans.push_back(poss);
            return;
        }

        for(int i=0;i<n;i++){
            if(st.find(nums[i]) == st.end()){
                poss.push_back(nums[i]);
                st.insert(nums[i]);

                solve(poss,nums);

                poss.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int> poss;
        solve(poss,nums);

        return ans;
    }
};