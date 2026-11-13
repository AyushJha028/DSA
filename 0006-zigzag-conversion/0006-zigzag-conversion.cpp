class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int n=s.size();
        string ans = "";
        for(int i=0;i<numRows;i++){
            int increment = 2 * (numRows-1);
            for(int j=i;j<n;j += increment){
                ans += s[j];

                if(i>0 && i<numRows-1 && j+increment - 2*i < n){
                    ans += s[j+increment - 2*i];
                }
            }
        }
        return ans;
    }
};