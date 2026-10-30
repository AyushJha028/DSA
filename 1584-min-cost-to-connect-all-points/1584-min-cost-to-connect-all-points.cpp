class Solution {
public:
    vector<int> parent;
    vector<int> rank; 

    int find(int x){
        if(parent[x]  == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y)
            return;

        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_y] < rank[parent_x]){
            parent[parent_y] = parent_x;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    int Kruskal(vector<vector<int>>& adj){
        int sum =0;

        for(auto& ad:adj){
            int u=ad[0];
            int v = ad[1];
            int wt = ad[2];
            
            int parent_u = find(u);
            int parent_v = find(v);

             if(parent_u != parent_v){
                Union(u,v);
                sum += wt;
             }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V= points.size();

        parent.resize(V);
        rank.resize(V,0);

        for(int i=0;i<V;i++){
            parent[i] = i;
        }

        vector<vector<int>> adj;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj.push_back({i,j,dist});
            }
        }

        auto comparator = [&](auto& v1, auto& v2) {
            return v1[2] < v2[2];
        };
        sort(adj.begin(),adj.end(),comparator);
        return Kruskal(adj);
    }
};