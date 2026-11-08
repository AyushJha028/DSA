class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> colServer(n,0);
        vector<int> rowServerAl(m,-1);

        int count  =0 ;

        for(int i=0;i<m;i++){
            int temp =0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    colServer[j]++;
                    temp++;
                    rowServerAl[i] = j;
                }
            }

            if(temp > 1){
                count += temp;
                rowServerAl[i] = -1;
            }
        }
        for(int i=0;i<m;i++){
            if(rowServerAl[i] != -1){
                int col = rowServerAl[i];
                if(colServer[col] > 1){
                    count +=1;
                }
            }
      }
    return count;
    }
};