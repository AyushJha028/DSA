class Solution {
public:
    int newNum(int n){
        int val=0;
        while(n >0){
            int dig= n%10;
            val  += dig * dig;
            n=n/10;
        }
        return val;
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