class Solution {
public:
    unordered_map<char,string> mpp ={
        {'2', "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv" },
        {'9' , "wxyz"}
    };
    vector<string> ans;
    int n;

    void solve(int idx,string digits,string temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        string letters = mpp.at(digits[idx]);
        for(char l:letters){
            solve(idx+1,digits,temp+l);
        }
    }

    vector<string> letterCombinations(string digits) {
         n=digits.size();
        if(n == 0){
            return ans;
        }
       
        solve(0,digits,"");
        return ans;
    }
};