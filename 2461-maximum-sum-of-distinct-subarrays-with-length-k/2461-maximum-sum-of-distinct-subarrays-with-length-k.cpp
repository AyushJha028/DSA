class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(k > n)
            return 0;
        unordered_map<int,int> mpp;
        long long ans=0;
        long long sum=0;
        int j=0;
        for(int i=0;i<k;i++){
            sum += nums[i];
            mpp[nums[i]]++;
        }

        if(mpp.size() == k) 
            ans = sum;

        for(int i=k;i<n;i++){
            sum += nums[i];
            mpp[nums[i]]++;

            sum -= nums[i-k];
            mpp[nums[i-k]]--;

            if(mpp[nums[i-k]] == 0)
                mpp.erase(nums[i-k]);

            if(mpp.size() == k)
                ans = max(sum,ans);
        }
        return ans;
    }
};