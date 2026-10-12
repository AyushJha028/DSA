class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int> temp,int n,int k){
        
            if(temp.size() == k){
                ans.push_back(temp);
                return;
            }

            if(i>n)
                return;
            
    
        for(int idx=i;idx<=n;idx++){
            temp.push_back(idx);
            solve(idx+1,temp,n,k);
            temp.pop_back();
           // solve(idx+1,temp,n,k);
        }


    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,temp,n,k);

        return ans;
    }
};