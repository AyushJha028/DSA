class Solution {
public:

    bool dfs(vector<vector<int>>& graph,vector<int>& colored,int  u,int color){
        colored[u] = color;

        for(int& e:graph[u]){
            if(colored[e] == colored[u]){
                return false;
            }
            if(colored[e] == -1){ 
                if(!dfs(graph,colored,e,1-color))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
      
        int color=1;
        vector<int> colored(n,-1);
        for(int i=0;i<n;i++){
            if(colored[i] == -1){
                if(dfs(graph,colored,i,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};