class Solution {
public:
    int n;
    string str;

    vector<vector<int>> cost;
    vector<vector<int>> dp;

    int getCost(int i,int  j){
        int len = j-i+1;

        // if(cost[i][j] != INT_MAX){
        //     return cost[i][j];
        // }

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

        return  minCost;
    }

    // int solve(int start, int k){
    //     if(k == 0){
    //         if(start == n)
    //             return 0;
            
    //         return INT_MAX;
    //     }

    //     if(start + 2*k > n)
    //         return INT_MAX;
        
    //     if(dp[start][k] != -1){
    //         return dp[start][k];
    //     }
    //     int result = INT_MAX;

    //     for(int end = start+1;end<n;end++){
    //         int remainingCost = solve(end+1,k-1);

    //         if(remainingCost == INT_MAX)
    //             continue;

    //         result = min(result,getCost(start,end) + remainingCost);                
    //     }

    //     return dp[start][k] = result;
    // }

    int minimumChanges(string s, int k) {
        str = s;
        n = s.size();

        cost.assign(n+1, vector<int>(n+1,INT_MAX));
        dp.assign(n+1,vector<int>(k+1,INT_MAX));
        
        dp[n][0] = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cost[i][j] = getCost(i,j);
            }
        }

        for(int start =n;start >= 0;start--){
            for(int pieces = 1;pieces <= k;pieces++){
                if(start + 2*pieces > n)
                    continue;
                
                int result = INT_MAX;

                for(int end = start+1;end <n;end++){
                    int remainingCost = dp[end+1][pieces-1];

                    if(remainingCost == INT_MAX)    
                        continue;

                    result = min(result,cost[start][end] + remainingCost);
                }

                dp[start][pieces] = result;
            }
        }


        return dp[0][k];
    }
};