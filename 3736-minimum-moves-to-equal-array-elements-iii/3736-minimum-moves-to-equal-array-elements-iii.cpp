class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int num : nums){
            maxi = max(maxi,num);
        }

        int count = 0;

        for(int num : nums){
            count += abs(maxi - num);
        }

        return count;
    }
};