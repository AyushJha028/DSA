class Solution {
public:
    vector<vector<int>> ans;
    int n;
  //  unordered_set<int> st;

    void solve(vector<int>& nums,vector<int>& temp,int idx){
        if(idx >= n){
            ans.push_back(temp);
            return;
        }
        
        
        temp.push_back(nums[idx]);
           // st.insert(nums[i]);

        solve(nums,temp,idx+1);
            //st.erase(nums[i]);
        temp.pop_back();

        solve(nums,temp,idx+1);
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        solve(nums,temp,0);

        return ans;
    }
};