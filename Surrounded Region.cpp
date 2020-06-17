class Solution {
public:
    void fill(vector<vector<char>>& board, int i, int j){
        if(i>=0 && j>=0 && i<board.size() && j<board[0].size()){
            if(board[i][j] == '-'){
                board[i][j] = 'O';
                fill(board, i-1, j);
                fill(board, i+1, j);
                fill(board, i, j+1);
                fill(board, i, j-1);
            }
        }
    }
    //SIMILAR TO FLOOD FILL
    void solve(vector<vector<char>>& board) {
        
        //replace all Os to '-'s
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='O') board[i][j]='-';
        // for(int i=0;i<board.size();i++){
        //     for(int j=0;j<board[0].size();j++)
        //         cout<<board[i][j]<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";
        
        //now  flood fill all '-'s in the border and convert it to 'O's again
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if((i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1) && board[i][j]=='-') 
                    fill(board, i, j);
            }
        // for(int i=0;i<board.size();i++){
        //     for(int j=0;j<board[0].size();j++)
        //         cout<<board[i][j]<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";
        
        //Now convert the remaining '-'s that are neither in the border nor connected to border to 'X'
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='-') board[i][j]='X';
        // for(int i=0;i<board.size();i++){
        //     for(int j=0;j<board[0].size();j++)
        //         cout<<board[i][j]<<" ";
        //     cout<<"\n";
        // }
    }
};