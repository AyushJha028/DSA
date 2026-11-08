class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> colServer(n,0);
        vector<int> rowServer(m,0);
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    colServer[j]++;
                    rowServer[i]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && (colServer[j] >1 || rowServer[i] > 1)){
                    count++;
                }
            }
        }
        return count;
    }
};