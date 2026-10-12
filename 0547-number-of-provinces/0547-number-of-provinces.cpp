class Solution {
public:
    int n;
    int count=0;
    void dfs(unordered_map<int,vector<int>>& adj,vector<bool>& isVisited, int u){
        if(isVisited[u] == true){
            return;
        }
        isVisited[u] = true;
        for(auto& e:adj[u]){
            if(!isVisited[e]){
                dfs(adj,isVisited,e);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> isVisited(n,false);
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                dfs(adj,isVisited,i);
                count++;
            }
        }
        
        return count;
    }
};