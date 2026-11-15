class Solution {
public:
    int m,n,s;
    vector<vector<int>> directions ={{0,1},{1,0},{0,-1},{-1,0}};

    bool find(int i,int j,vector<vector<char>>& board,string word, int idx){

        if(idx == s){
            return true;
        }

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$'){
            return false;
        }

        if(board[i][j] != word[idx]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto dir:directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(find(x,y,board,word,idx+1)){
                return true;
            }
        }
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        s = word.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0] && find(i,j,board,word,0)){
                    return true;
                }
            }
        }

        return false;    
    }
};