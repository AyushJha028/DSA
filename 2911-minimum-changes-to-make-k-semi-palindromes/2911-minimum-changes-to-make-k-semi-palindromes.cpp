class Solution {
public:
    int n;
    string str;

    vector<vector<int>> cost;
    vector<vector<int>> dp;

    int getCost(int i,int  j){
        int len = j-i+1;

        if(cost[i][j] != -1){
            return cost[i][j];
        }

        int minCost = INT_MAX;

        for(int d=1;d<len;d++){
            if(len % d != 0)
                continue;
            
            int price = 0;
            for(int group= 0;group<d;group++){
                int l =i+group;
                int r = l + (len/d -1)*d;

                while(l < r){
                    if(str[l] != str[r]){
                        price++;
                    }

                    l += d;
                    r -= d;
                }
            }
            minCost= min(minCost,price);
        }

        return cost[i][j] = minCost;
    }

    int solve(int start, int k){
        if(k == 0){
            if(start == n)
                return 0;
            
            return INT_MAX;
        }

        if(start + 2*k > n)
            return INT_MAX;
        
        if(dp[start][k] != -1){
            return dp[start][k];
        }
        int result = INT_MAX;

        for(int end = start+1;end<n;end++){
            int remainingCost = solve(end+1,k-1);

            if(remainingCost == INT_MAX)
                continue;

            result = min(result,getCost(start,end) + remainingCost);                
        }

        return dp[start][k] = result;
    }

    int minimumChanges(string s, int k) {
        str = s;
        n = s.size();

        cost.assign(n+1, vector<int>(n+1,-1));
        dp.assign(n+1,vector<int>(k+1,-1));

        return solve(0,k);
    }
};