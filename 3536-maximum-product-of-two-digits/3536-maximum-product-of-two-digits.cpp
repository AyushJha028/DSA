class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int ans=1;
        int m=s.size();
        sort(s.begin(),s.end());
        ans = ans * (s[m-1]-'0') * (s[m-2]-'0');
        return ans;
    }
};