class Solution {
public:
    int N;
    vector<vector<string>> ans;
    unordered_set<int> cols;
    unordered_set<int> antidiag;
    unordered_set<int> diag;

    void solve(vector<string>& board, int row){
        if(row >= N ){
            ans.push_back(board);
            return;
        }

        for(int col =0;col<N;col++){
            int da = row + col;
            int ada = row - col;

            if(cols.find(col) != cols.end() || diag.find(da) != diag.end() || antidiag.find(ada) != antidiag.end() ){
                continue;
            }

            cols.insert(col);
            diag.insert(da);
            antidiag.insert(ada);

            board[row][col] = 'Q';

            solve(board,row+1);

            cols.erase(col);
            diag.erase(da);
            antidiag.erase(ada);

            board[row][col] = '.';
        }
    }
    int totalNQueens(int n) {
        N = n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return ans.size();
    }
};