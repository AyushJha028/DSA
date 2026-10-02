class Solution {
public:
    vector<string> ans;

    bool isValid(string path){
        stack<char> st;
        int n=path.size();
        for(int i=0;i<n;i++){
            if(st.empty() && path[i] == ')'){
                return false;
            }
            else if(!st.empty() && (st.top() == '(' && path[i] == ')')){
                st.pop();
            }
            else{
                st.push(path[i]);
            }
        }
        return st.empty();
    }

    void solve(string& path,int n){
        if(path.size() == 2*n){
            if(isValid(path)){
                ans.push_back(path);
            }
            return;
        }
        path.push_back('(');
        solve(path,n);
        path.pop_back();

        path.push_back(')');
        solve(path,n);
        path.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string path="";
        solve(path,n);
        return ans;
    }
};