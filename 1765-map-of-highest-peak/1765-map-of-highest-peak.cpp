class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<P> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(! q.empty()){
            int size = q.size();

            while(size--){
                P curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto& dir: directions){
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if(ni >= 0 && nj >= 0 && ni<m && nj<n && height[ni][nj] == -1){
                        height[ni][nj] = height[i][j]  + 1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return height;
    }
};