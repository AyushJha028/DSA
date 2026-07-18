class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for(auto& n:nums){
            min_val=min(min_val,n);
            max_val = max(max_val,n);
        }
        return gcd(min_val,max_val);
    }
};