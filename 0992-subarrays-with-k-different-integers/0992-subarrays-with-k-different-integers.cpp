class Solution {
public:

    int solve(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int> mpp;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            while(mpp.size() > k){
                mpp[nums[j]]--;
                if(mpp[nums[j]] == 0){
                    mpp.erase(nums[j]);
                }
                j++;
            }
            count  += i-j+1;
        }
        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};