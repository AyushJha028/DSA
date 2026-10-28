class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int> open;
        stack<int> astrick;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '('){
                open.push(i);
            }
            else if(ch == '*'){
                astrick.push(i);
            }
            else{
                if(! open.empty()){
                    open.pop();
                }
                else if(! astrick.empty()){
                    astrick.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(! open.empty() && !astrick.empty()){
            int o = open.top();
            int a = astrick.top();
            open.pop();
            astrick.pop();
            if(o > a){
                return false;
            }
        }
        return open.empty();
    }
};