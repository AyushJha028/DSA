class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;

        int n=nums.size();
        int i=0;
        int j=0;
        long long prod=1;
        long long ans=0;
        while(i<n){
            prod *= nums[i];
            while(prod >= k && j<n){
                prod /= nums[j];
                j++;
            }
            ans += (i-j+1);
            i++;
        }
        return ans;
    }
};