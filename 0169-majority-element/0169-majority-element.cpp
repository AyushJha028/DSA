class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int num : nums){
            mpp[num]++;
            if(mpp[num] > n/2)
                return num;
        }
        return -1;
    }
};