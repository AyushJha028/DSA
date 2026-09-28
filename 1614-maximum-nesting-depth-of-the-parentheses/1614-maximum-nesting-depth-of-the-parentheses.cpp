class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                st.pop();
            }
            else if(s[i] == '('){
                st.push(s[i]);
                int x= st.size();
                ans = max(ans,x);
            }
            else{
                continue;
            }
        } 
        return ans;
    }
};