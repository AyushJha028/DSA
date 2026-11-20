class Solution {
public: 
    int n;
    
    int find(int i,int target,vector<int>& nums){
        int j = lower_bound(nums.begin() + i, nums.end(), target) - nums.begin();

        if(j <n && nums[j] == target){
            return j;
        }

        return -1;
    } 

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        sort(nums.begin(),nums.end());
        int ans=1;

        for(int i=n-1;i >= 0;i--){
            for(int inc =0;inc<2;inc++){
                int curr = nums[i] + inc;
                int len =1;

                int j = find(i+1,curr+1,nums);
                if(j != -1){
                    len = max(len,1+dp[j][0]);
                }

                j = find(i+1,curr,nums);
                if(j != -1){
                    len = max(len,1+dp[j][1]);
                }

                dp[i][inc] = len;
                ans = max(ans,len);
            }

        }

        return ans;
    }
};