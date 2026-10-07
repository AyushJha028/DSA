class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int min_sum = nums[0];
        int mini = nums[0];
        int maxi = nums[0];

        for(int i=1;i<n;i++){
            max_sum = max(max_sum + nums[i], nums[i]);
            min_sum = min(min_sum + nums[i] , nums[i]);
            maxi = max(maxi , max_sum);
            mini = min(mini, min_sum);
        }
        return max(maxi,abs(mini));
    }
};