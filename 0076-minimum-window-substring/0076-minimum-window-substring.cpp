class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n < m)
            return "";

        int requiredCount = m ;
        int i=0;
        int j=0;
        int minStart = 0;
        int minWindow = INT_MAX;

        unordered_map<char,int> mpp;

        for(char ch:t){
            mpp[ch] ++;
        }

        while(j<n){
            char ch =s[j];
            if(mpp[ch] > 0){
                requiredCount--;
            }
            mpp[ch]--;

            while(requiredCount == 0){
                if(minWindow > j-i+1){
                    minWindow = j-i+1;
                    minStart = i;
                }
                char ch_i = s[i];
                mpp[ch_i]++;
                if(mpp[ch_i] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        if(minWindow == INT_MAX){
            return "";
        }
        return s.substr(minStart,minWindow);
    }
};