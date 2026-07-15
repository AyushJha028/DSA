class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        if(m<n)
            return false;
        if(n==0)
            return true;
        unordered_map<char,int> ransom;
        unordered_map<char,int> mag;
        for(auto &r:ransomNote){
            ransom[r]++;
        }
        for(auto& m:magazine){
            mag[m]++;
        }
        for(char ch='a';ch<='z';ch++){
            if(ransom[ch] > mag[ch])
                return false;
        }
        return true;
    }
};