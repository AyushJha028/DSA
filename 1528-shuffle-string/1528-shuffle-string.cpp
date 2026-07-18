class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans;
        int n=s.size();
        ans.resize(n);
        int i=0;
        for(auto& str:s){
            ans[indices[i]] =str;
            i++;
        }
        return ans;
    }
};