class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        vector<bool> temp(256,0);
        int j=0;
        for(int i=0;i<n;i++){
            if(temp[s[i]] == 0){
                ans=max(ans,i-j+1);
            }
            while(temp[s[i]] == 1){
                temp[s[j]] =0;
                j++;
            }
            temp[s[i]] =1;
        }
        return ans;
    }
};