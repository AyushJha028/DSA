class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        int min_el = INT_MAX;
        for(int i=0;i<n;i++){
            min_el = min(nums[i],min_el);
        }

        for(int i=0;i<n;i++){
            count += (nums[i] - min_el);
        }
        return count;
    }
};