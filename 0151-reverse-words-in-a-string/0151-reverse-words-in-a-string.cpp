class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int j=n-1;
       while(j>=0){
            while(j>=0 && s[j] == ' ')
                j--;
            if(j<0)
                break;
            string temp="";
            while(j>=0 && s[j] != ' '){
                temp += s[j];
                j--;
            }
            reverse(temp.begin(),temp.end());
            if(!ans.empty())
                ans += ' ';
            ans += temp;
        }
        return ans;
    }
};