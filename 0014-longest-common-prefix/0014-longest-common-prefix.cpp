class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        int  n=strs.size();
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        int m=min(first.size(),last.size());
        for(int i=0;i<m;i++){
            if(first[i] != last[i])
                return ans;
            ans += first[i];            
        }
        return ans;
    }
};