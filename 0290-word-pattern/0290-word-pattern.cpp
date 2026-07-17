class Solution {
public:

    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mpp1;
        unordered_map<string,char> mpp2;
        int n=pattern.size();
        string word;
        stringstream ss(s);
        for(int i=0;i<n;i++){
            char ch=pattern[i];
            if(!(ss >> word))
                return false;
           // string temp=word;
            //ss >> word;
            if((mpp1.find(ch) != mpp1.end() && mpp1[ch] != word) || (mpp2.find(word) != mpp2.end() && mpp2[word] != ch))
                return false;

            mpp1[ch] = word;
            mpp2[word] =ch;
        }
        if(ss >>word)
                return false;
        return true;
    }
};