class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq [26]={0};
        for(auto &m:magazine){
            freq[m-'a']++;
        }
        for(auto &r:ransomNote){
            freq[r-'a']--;
            if(freq[r -'a'] < 0)
                return false;
        }
        return true;
    }
};