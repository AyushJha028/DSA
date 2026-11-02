class Solution {
public:
    pair<int,int> bfs(unordered_map<int,vector<int>>& adj, int source){
        queue<int> q;
        q.push(source);

        unordered_map<int,bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthest = source;

        while(! q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();
                
                farthest = curr;

                for(auto& ngbr: adj[curr]){
                    if(visited[ngbr] == false){
                        visited[ngbr] = true;
                        q.push(ngbr);
                    }
                }
            }
            if(! q.empty())
                distance++;
        }


        return {farthest,distance};
    }   

    int diameter(unordered_map<int,vector<int>>& adj){
        auto[farthest,dist] = bfs(adj,0);

        auto[node,distance] = bfs(adj,farthest);

        return distance;
    }
    unordered_map<int,vector<int>> buildADJ(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = buildADJ(edges1);
        unordered_map<int,vector<int>> adj2 = buildADJ(edges2);

        int d1 = diameter(adj1);
        int d2 = diameter(adj2);

        int conn = (d1+1)/2 + (d2+1)/2 + 1;

        return max(max(d1,d2),conn);
    }
};