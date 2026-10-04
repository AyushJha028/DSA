class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                int t1= (i-k >= 0)? i-k : 0;
                int t2= (j-k >= 0)? j-k : 0;
                int p1= (i+k <= m-1)? i+k : m-1;
                int p2= (j+k <= n-1)? j+k : n-1;
                for(int r=t1;r<= p1;r++){
                    for(int c=t2;c <= p2;c++){
                        sum += mat[r][c];
                    }
                    
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};