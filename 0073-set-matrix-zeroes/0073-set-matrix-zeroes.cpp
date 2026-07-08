class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>> k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                    k.push_back({i,j});
            }
        }
        for(int i=0;i<k.size();i++){
            int x=k[i].first;
            int y=k[i].second;
            for(int j=0;j<n;j++){
                matrix[j][y] =0;
            }
            for(int j=0;j<m;j++){
                matrix[x][j] = 0;
            }
        }
    }
};