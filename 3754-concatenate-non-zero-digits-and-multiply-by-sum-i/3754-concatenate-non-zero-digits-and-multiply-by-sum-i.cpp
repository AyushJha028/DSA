class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0 || n==1)
            return n;
        long long ans;
        string temp=to_string(n);
        string nonze="";
        long long sum=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i] !='0'){
                nonze += temp[i];
                sum += temp[i] -'0';
            }
            else
                continue;
        }
        int val=stoi(nonze);
        ans= sum * val;
        return ans;
    }
};