class Solution {
public:
    int m,n;
    vector<vector<int>> directions {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,pair<int,int>> p;

    bool isSafe(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size();
        n= heights[0].size();

        priority_queue<p,vector<p>, greater<p>> pq;
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        result[0][0] = 0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int d = pq.top().first;
            auto coord = pq.top().second;
            int x =coord.first;
            int y = coord.second;
            pq.pop();

            if(x == m-1 && y == n-1){
                return d;
            }
            for(auto& dir:directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_,y_)){
                    int diff = abs(heights[x][y] - heights[x_][y_]);
                    int maxdiff = max(diff,d);

                    if(result[x_][y_] > maxdiff){
                        result[x_][y_] = maxdiff;
                        pq.push({maxdiff,{x_,y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};