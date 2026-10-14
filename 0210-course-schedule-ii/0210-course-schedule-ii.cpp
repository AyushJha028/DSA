class Solution {
public:
    bool hasCycle;

    void dfs(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited, vector<bool>& inRecursion,stack<int>& st){
        inRecursion[u] = true;
        visited[u] = true;

        for(int& e:adj[u]){
            if(inRecursion[e] == true){
                hasCycle = true;
                return;
            }

            if(!visited[e]){
                dfs(adj,e,visited,inRecursion,st);
            }
        }
        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(auto& e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[v].push_back(u);
        }

        stack<int> st;

        for(int i=0;i<numCourses;i++){
           // hasCycle = false;
            if(! visited[i]){
                dfs(adj,i,visited,inRecursion,st);
            }
            
        }
        if(hasCycle){
            return {};
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};