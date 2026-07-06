class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int j=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum >= target){
                sum -= nums[j];
                ans= min(ans,i-j+1);
                j++;
            }
        }
        if(ans ==  INT_MAX)
            return 0;
        return ans;
    }
};