class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        int time = 0;
        while(! q.empty()){
            int size = q.size();
            while(size--){
                P curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto& dir:directions){
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if(ni >= 0 && nj >= 0 && ni<m && nj<n && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        q.push({ni,nj});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh == 0)
            return time-1;

        return -1;
    }
};