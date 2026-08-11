class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int low=0;
        int high=n-1;
        int mid;
        while(low <= high){
            mid=(low+high)/2;
            if(nums[low] < nums[high]){
                ans=min(ans,nums[low]);
                break;
            }
            else if(nums[mid] < nums[high]){
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
            else{
                ans=min(ans,nums[high]);
                low=mid+1;
            }
        }
        return ans;
    }
};