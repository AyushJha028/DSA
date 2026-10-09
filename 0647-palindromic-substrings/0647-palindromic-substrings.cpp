class Solution {
public:
    int count1=0;
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
                count1++;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    ans ++;
                    if(count1 == 2){
                        break;
                        count1=0;
                    }
                }
            }
           
        }
        return ans;
    }
};