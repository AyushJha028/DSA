class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() -1;
        int n = b.size() - 1;

        string ans;

        int sum =0;
        int carry = 0;

        while(m >= 0 || n >= 0){
            sum = carry;
            if(m >= 0){
                sum += a[m] -'0';
                m--;
            }
            if(n >= 0){
                sum += b[n] -'0';
                n--;
            }
            if(sum % 2 ==0){
                ans.push_back('0');
            }
            else{
                ans.push_back('1');
            }

            carry = sum /2;
        }
        
        if(carry){
            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};