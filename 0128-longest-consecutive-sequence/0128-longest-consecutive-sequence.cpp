class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        vector<int> temp;
        set<int> st(nums.begin(),nums.end());
        for(int x:st){
            temp.push_back(x);
        }
        int ans=0;
        if(temp.size()==1)
            return 1;
        int diff=temp[1] -temp[0];
        int count=1;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i+1] -temp[i] == 1){
                count++;
            }
            else{
                //diff=temp[i+1] - temp[i];
                count=1;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};