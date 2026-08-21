class Solution {
public:
    int hammingWeight(int n) {
        vector<int> temp;
        int count=0;
        while(n>0){
            temp.push_back(n%2);
            n=n/2;
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i] == 1)
                count++;
        }
        return count;
    }
};