class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> add;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch1=s[i];
            char ch2=t[i];

            if((mpp.find(ch1)  != mpp.end() && mpp[ch1] != ch2) ||
                (add.find(ch2) != add.end() && add[ch2] != ch1))
                return false;
            mpp[ch1] = ch2;
            add[ch2] = ch1;
        }
        return true;
    }
};