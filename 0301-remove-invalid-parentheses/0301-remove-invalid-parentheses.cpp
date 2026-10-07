class Solution {
public:
   
    unordered_set<string> st;
    int n;
    int max_len=0;

    void solve(string& s,int i,string& curr,int count){
        if(count < 0)
            return;
        
        if(i==n){
            if(count == 0){
                if(curr.size() > max_len){
                    max_len  = curr.size();
                    st.clear();
                }
                if(curr.length() == max_len){
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[i] != ')' && s[i] != '('){
            curr.push_back(s[i]);
            solve(s,i+1,curr,count);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);

        solve(s,i+1,curr,count + (s[i] == '(' ? 1 : -1));

        curr.pop_back();

        solve(s,i+1,curr,count);


    }
    vector<string> removeInvalidParentheses(string s) {
        string curr="";
        n=s.size();
        st.clear();
        
        solve(s,0,curr,0);
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};