class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void solve(vector<int>& temp,unordered_map<int,int>& mpp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(auto& [num,count] : mpp){
            if(count == 0) 
                continue;

            temp.push_back(num);
            mpp[num]--;

            solve(temp,mpp);

            temp.pop_back();
            mpp[num]++;
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        unordered_map<int,int> mpp;
        for(auto& num:nums){
            mpp[num]++;
        }    

        vector<int> temp;
        solve(temp,mpp);

        return ans;
    }
};