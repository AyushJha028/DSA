class Solution {
public:

    vector<vector<int>> directions = {{0,1}, { 1,0},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int,int>>dq;
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        result[0][0] = grid[0][0];
        dq.push_front({0,0});
        while(!dq.empty()){
                auto curr = dq.front();
                dq.pop_front();
                int r = curr.first;
                int c = curr.second;

                for(auto& dir: directions){
                    int i = r  + dir[0];
                    int j = c + dir[1];

                    if(i < 0 || i>= m || j <0 || j>= n)
                        continue;
                    
                    if(result[r][c] + grid[i][j] < result[i][j]){
                            result[i][j] = result[r][c] + grid[i][j];

                            if(grid[i][j] == 0){
                                dq.push_front({i,j});
                            }
                            else{
                                dq.push_back({i,j});
                            }
                    }
                }
            
        }
        int x = result[m-1][n-1];

        return  health - x >= 1;
    }
};