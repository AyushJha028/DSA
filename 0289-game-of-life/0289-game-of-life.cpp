class Solution {
public:

    int liveNeighbours(vector<vector<int>>& curr,int i,int j,int m,int n){
        int count=0;
        if(i>0){
            if(curr[i-1][j] == 1)
                count++;
        }
        if(i<m-1){
            if(curr[i+1][j] == 1)
                count++;
        }
        if(j>0){
            if(curr[i][j-1] == 1)
                count++;
        }
        if(j<n-1){
            if(curr[i][j+1] ==1)
                count++;
        }
        if(i>0 && j>0){
            if(curr[i-1][j-1] == 1)
                count++;
        }
        if(i>0 && j<n-1){
            if(curr[i-1][j+1] ==1) 
                count++;
        }
        if(i<m-1 && j>0){
            if(curr[i+1][j-1] == 1)
                count++;
        }
        if(i<m-1 && j<n-1){
            if(curr[i+1][j+1] ==1)
                count++;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> vec(board.begin(),board.end());
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count =liveNeighbours(vec,i,j,m,n); // Counts Live Cell
                
                if(board[i][j]==1){
                    if(count < 2){
                        board[i][j] = 0;
                    }
                    else if(count ==2 || count ==3){
                        board[i][j] =1;
                    }
                    else if(count >3){
                        board[i][j] =0;
                    }
                }
                else{
                    if(count == 3){
                        board[i][j]=1;
                    }
                }
            }
        }

    }
};