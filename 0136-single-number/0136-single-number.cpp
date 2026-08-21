class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=0;
        for(auto num:nums){
            xor1 = xor1^ num;
        }
        return xor1;
    }
};