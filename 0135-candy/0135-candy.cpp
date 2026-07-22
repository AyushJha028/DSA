class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        //sort(ratings.began(),ratings.end());
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> total(n,1);
        int ans= 0;
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = max(left[i],left[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = max(right[i],right[i+1]+1);
            }
        }
        for(int i=0;i<n;i++){
            total[i] = max(left[i],right[i]);
        }
        for(int i=0;i<n;i++){
            ans += total[i];
        }
        return ans;
    }
};