class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int max_sum =nums[0];
        int min_sum =nums[0];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            sum += nums[i];
            max_sum = max(max_sum + nums[i],nums[i]);
            min_sum =min(min_sum + nums[i],nums[i]);
            maxi=max(max_sum,maxi);
            mini=min(min_sum,mini);
        }
        if(maxi <0)
            return maxi;
        return max(maxi,sum-mini);
    }
};