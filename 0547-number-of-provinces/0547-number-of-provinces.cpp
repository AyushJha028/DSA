class Solution {
public:
    int n;
    int count=0;
    void dfs(vector<vector<int>>& isConnected,vector<bool>& isVisited, int u){
        if(isVisited[u] == true){
            return;
        }
        isVisited[u] = true;
        for(int v=0; v<n;v++){
            if(!isVisited[v] && isConnected[u][v] == 1){
                dfs(isConnected,isVisited,v);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        // unordered_map<int,vector<int>> adj;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j] == 1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        vector<bool> isVisited(n,false);
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                dfs(isConnected,isVisited,i);
                count++;
            }
        }
        
        return count;
    }
};