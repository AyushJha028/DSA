class Solution {
public:
    bool bfs(vector<vector<int>>& graph,int u, vector<int>& colored,int color){
        colored[u] = color;
        queue<int> q;
        q.push(u);

        while(! q.empty()){
            int p=q.front();
            q.pop();

            for(int& e:graph[p]){
                if(colored[p] == colored[e]){
                    return false;
                }
                else if(colored[e] == -1){
                    colored[e] = 1-colored[p];
                    q.push(e);
                }
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
                if(! bfs(graph,i,colored,color)){
                    
                    return false;
                }
            }
        }

        return true;
    }
};