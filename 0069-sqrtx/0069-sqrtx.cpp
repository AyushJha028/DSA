class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0)
            return x;
        long long low=1;
        long long high=x/2;
        long long mid;
        long long  ans=0;
        
        while(low <= high){
            mid=(low+high)/2;
            long long val= 1LL *mid*mid;
            if(val <= x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};