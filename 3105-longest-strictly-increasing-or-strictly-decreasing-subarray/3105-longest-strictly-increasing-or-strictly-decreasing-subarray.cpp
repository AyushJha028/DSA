class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int dec = 1;
        int inc = 1;
        int incCount =1;
        int decCount = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                incCount +=1;
                inc = max(inc,incCount);
            }
            else{
                incCount = 1;
            }
        }

        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                decCount++;
                dec = max(dec,decCount);
            }
            else{
                decCount = 1;
            }
        }

        return max(dec,inc);
    }
};