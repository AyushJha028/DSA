class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto& num:mpp){
            if(num.second == 1)
                return num.first;
        }
        return -1;
    }
};