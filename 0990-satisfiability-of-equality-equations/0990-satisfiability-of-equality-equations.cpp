class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i] = i;
        }

        for(string& s:equations){
            if(s[1] == '='){
                Union(s[0]- 'a' , s[3]-'a');
            }
        }

        for(string& s:equations){
            if(s[1] == '!'){
                int first= s[0]-'a';
                int second = s[3] - 'a';
                int parent_first = find(first);
                int parent_second = find(second);
                if(parent_first == parent_second)
                    return false;
            }
        }

        return true;
    }
};