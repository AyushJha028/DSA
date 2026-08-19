class Solution {
public:
    int maximum(vector<int>& piles){
        int maxi=INT_MIN;
        for(auto& p:piles){
            maxi=max(p,maxi);
        }
        return maxi;
    }

    bool isAble(vector<int>& piles,int mid,int h){
        long long int count=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            count += (piles[i] + mid-1) /mid;
        }
        return count <=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_val=maximum(piles);
        int low=1;
        int mid;
        int ans=0;
        int high=max_val;
        while(low <= high){
            mid=(low + high)/2;
            if(isAble(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};