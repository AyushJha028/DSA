class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto num:nums){
            mini=min(mini,num);
            maxi=max(maxi,num);
        }
        sort(nums.begin(),nums.end());
        int j=0;
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(j<n && nums[j] == i)
                j++;
            else
                ans.push_back(i);
        }
        return ans;
    }
};