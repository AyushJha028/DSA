class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n == 1){
            return n;
        }
        
        int i=0;
        int k=0;
        while(i<n){
           
            int count =0;
            char ch = chars[i];
            while(i<n && chars[i] == ch){
                count++;
                i++;
            }

            chars[k] = ch;
            k++; 
            
            if(count > 1 ){
                string s =to_string(count);
                int j=0;
                while(j<s.size()){
                    chars[k] = s[j];
                    k++;
                    j++;
                }
            }
           // i++;
        }
        return k;
    }
};