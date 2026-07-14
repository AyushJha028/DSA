class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        vector<int> pre(n,1);
        int pro=1;
        for(int i=0;i<n;i++){
            pre[i] = pro;
            pro *= nums[i];
        }
        vector<int> right(n,1);
        int r=1;
        for (int i=n-1;i>=0;i--){
            right[i] =r;
            r *= nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i] = pre[i] *right[i];
        }
        return ans;
    }
};