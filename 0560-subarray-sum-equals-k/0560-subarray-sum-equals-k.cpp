class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mpp.find(sum - k) != mpp.end()){
                ans += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return ans;
    }
};