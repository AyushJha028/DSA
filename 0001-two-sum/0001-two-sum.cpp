class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        //mpp[0]=1;
        for(int i=0;i<n;i++){
            int t=target - nums[i];
            if(mpp.find(t) != mpp.end()){
                return {i,mpp[t]};
            } 
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};