class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        int pre_sum=0;
        int suff_sum=0;
        for(int i=0;i<n;i++){
            pre_sum += nums[i];
            pre[i] = pre_sum;
        }
        for(int i=n-1;i>=0;i--){
            suff_sum += nums[i];
            suff[i] = suff_sum;
        }
        for(int i=0;i<n;i++){
            if(pre[i] == suff[i])
                return i;
        }
        return -1;
    }
};