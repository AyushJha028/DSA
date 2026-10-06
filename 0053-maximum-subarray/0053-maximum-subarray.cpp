class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int sum=nums[0];
        for(int i=01;i<n;i++){
            sum = max(nums[i],nums[i] + sum);
            ans=max(sum,ans);
        }
        return ans;
    }
};