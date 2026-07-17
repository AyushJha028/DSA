class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        if(s.size() > t.size())
            return false;
        for(auto& ch:s){
            mpp1[ch]++;
        }
        for(auto& ch:t){
            mpp2[ch]++;
        }
        for(char ch='a';ch<='z';ch++){
            if(mpp1[ch] != mpp2[ch])
                return false;
        }
        return true;
    }
};