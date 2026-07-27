class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && (long long) nums[j+1] - (long long )nums[j] == 1){
                j++;
            }
            if(i==j){
                ans.push_back(to_string(nums[i]));
            }
            else{
                string temp= to_string(nums[i]) +"->" + to_string(nums[j]);
                ans.push_back(temp);
            }
            i=j+1;
        }
        return ans;
    }
};