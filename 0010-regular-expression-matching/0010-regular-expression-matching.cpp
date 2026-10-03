class Solution {
public:
    int t[21][21];
    bool solve(string s,string p,int i,int j){
        if(p.length() == j){
            if(s.length() == i){
                return true;
            }
            return false;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }

        bool first = false;

        if(i < s.length()  && (p[j] == s[i] || p[j] == '.' )){
            first = true;
        }

        if(p[j+1] == '*'){
            bool not_take =  solve(s,p,i,j+2);
            bool take = first && solve(s,p,i+1,j);

            return t[i][j] =  not_take || take;
        }

        return t[i][j] = first && solve(s,p,i+1,j+1);
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(s,p,0,0);
    }
};