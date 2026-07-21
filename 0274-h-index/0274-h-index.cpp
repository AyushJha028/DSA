class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        // if(n==1)
        //     return n;
        sort(citations.begin(),citations.end());
       // int ans=0;
        for(int i=0;i<n;i++){
            if(n-i <= citations[i] )
                return n-i;
        }
        return 0;
    }
};