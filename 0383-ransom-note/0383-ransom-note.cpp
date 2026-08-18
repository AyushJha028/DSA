class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> rpp;
        unordered_map<char,int> mpp;
        for(auto& r:ransomNote){
            rpp[r]++;
        }
        for(auto& m:magazine){
            mpp[m]++;
        }
        for(char ch='a';ch<='z';ch++){
            if(mpp[ch] < rpp[ch]){
                return false;
            }
        }
        return true;
    }
};