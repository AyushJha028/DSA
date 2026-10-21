class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        int n=s.size();

        if(n==2){
            return -1;
        }
        int min_char = *min_element(s.begin(),s.end());
        int max_char = *max_element(s.begin(),s.end());

        int min_itm = *min_element(s.begin()+1,s.end()-1);
        int max_itm = *max_element(s.begin()+1,s.end()-1);

        if(s[0] == min_char)
            return 1;
        
        if(s[n-1] == max_char)
            return 1;

        if(s[0] > max_itm && s[n-1] < min_itm){
            return 3;
        }

        return 2;
    }
};