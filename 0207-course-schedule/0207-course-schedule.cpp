class Solution {
public:
    int n;
    bool dfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int u,vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(int& e: adj[u]){
            if(!visited[e] &&  dfs(adj,visited,e,inRecursion)){
               return true;
            }
            else if(visited[e] && inRecursion[e]){
                return true;
            }
        }

        inRecursion[u] = false;
        return false;

    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites ) {
        n=numCourses;
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false);
        vector<bool> inRecursion(n,false);

        for(auto&  e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<n;i++){
                if(! visited[i] && dfs(adj,visited,i,inRecursion)){
                    return false;
                }
        }
        return true;

    }
};