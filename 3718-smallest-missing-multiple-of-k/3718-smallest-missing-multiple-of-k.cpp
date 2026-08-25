class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,int> mpp;
        for(auto num:nums){
            mpp[num]++;
        }
        for(int i=k;i<k*100; i+=k){
            if(mpp.find(i) == mpp.end()){
                return i;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i] % k==0)
                count++;
        }
        count+=1;
        
        // if(ans == INT_MAX && k==1)
        //     return 1;
        
        if(ans == INT_MAX)
            ans=k*count;

        return ans;
    }
};