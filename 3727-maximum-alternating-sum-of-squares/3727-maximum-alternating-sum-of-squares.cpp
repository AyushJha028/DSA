class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(nums[i] * nums[i]);
        }
        sort(temp.begin(),temp.end());
        int mid=n/2;
        long long small=0;
        for(int i=0;i<mid;i++){
            small += temp[i];
        }
        long long large = 0;
        for(int i=mid;i<n;i++){
            large += temp[i];
        }

        return large - small;
        
    }
};