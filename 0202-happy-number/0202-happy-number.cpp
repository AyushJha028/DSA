class Solution {
public:
    int newNum(int n){
        int ans=0;
        while(n>0){
            int digit=n%10;
            ans += digit * digit;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,int> mpp;
        while(mpp.find(n) == mpp.end()){
            mpp[n]++;
            n=newNum(n);
            if(n==1)
                return true;
        }
        return false;
    }
};