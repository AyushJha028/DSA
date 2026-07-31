class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mpp(26,0);
        for(char ch:word){
            mpp[ch-'a']++;
        }
        sort(mpp.begin(),mpp.end(),greater<int>());
        int count=0;
        for(int i=0;i<26;i++){
            count += mpp[i] * (i/8 + 1);
        }
        return count;
    }
};