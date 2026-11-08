class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    bool canConn = false;
                    for(int k=0;k<m;k++){
                        if(grid[k][j] == 1 && k != i){
                            canConn = true;
                            break;
                        }
                    }
                    if(canConn){
                        count +=1;
                    }
                    else{
                        for(int k=0;k<n;k++){
                        if(grid[i][k] == 1 && k != j){
                           count +=1;
                           break;
                        }
                    }
                    }
                }
            }
        }
        return count;
    }
};