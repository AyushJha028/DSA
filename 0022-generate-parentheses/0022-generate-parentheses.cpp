class Solution {
public:
    vector<string> ans;

    bool isValid(string curr){
        int n=curr.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty() && curr[i] == ')'){
                return false;
            }
            else if(!st.empty() && (st.top() == '(' && curr[i] == ')')){
                st.pop();
            } 
            else{
                st.push(curr[i]);
            }
        }
        return st.size() == 0;
    }

    void solve(string& curr, int n){
        if(curr.size() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr,n);
        return ans;
    }
};