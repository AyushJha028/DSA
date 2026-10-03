class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int j=0;
        int ans=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[fruits[i]]++;

            while(mpp.size() > 2){
                mpp[fruits[j]]--;
                if(mpp[fruits[j]] == 0){
                    mpp.erase(fruits[j]);
                }
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};