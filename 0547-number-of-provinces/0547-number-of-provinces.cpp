class Solution {
public:
    int n;
    void bfs(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited){
        queue<int> q;
        visited[u] = true;
        q.push(u);

        while(! q.empty()){
            int v=q.front();
            q.pop();
            for(auto& e: adj[v]){
                if(!visited[e]){
                    bfs(adj,e,visited);
                }
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
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            for(auto& e:adj[i]){
                if(! visited[e]){
                    bfs(adj,e,visited);
                    count++;
                }
            }
        }
        return count;
    }
};