class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int op=0;
        int mid = nums[n/2];
        for(auto& num : nums){
            op += abs(num - mid);
        }
        return op;
    }
};