class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree, outdegree;
        int V = pairs.size();
        for(auto& edge : pairs){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v] ++ ;
            outdegree[u] ++;
        }   

        int start = pairs[0][0];
        for(auto& it: adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                start = node;
                break;
            }
        }

        vector<int> path;
        stack<int> st;
        st.push(start);

        while(! st.empty()){
            int curr = st.top();
            if(! adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{
                path.push_back(curr);
                st.pop();
            }
        }

        reverse(path.begin(),path.end());
        int n=path.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            ans.push_back({path[i] , path[i+1]});
        }

        return ans;
    }
};