class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string ans="";
        int i=0,j=0,count=0;
        while(i<n && j<m){
            if(count%2 != 0){
                ans += word2[j];
                j++;
            }
            else{
                ans += word1[i];
                i++;
            }
            count++;
        }
        while(i<n){
            ans += word1[i];
            i++;
        }
        while(j<m){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};