https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<string> fillBoard(vector<int> pos, int n){
        vector<string> brd;
        for(int i=0; i<n; i++){
            string s="";
            for(int j=0;j<n; j++){
                if(pos[i] == j) s+='Q';
                else s+='.';
            }
            brd.push_back(s);
        }
        return brd;
    }
    void NQueensUtil(vector<vector<string>>& vec, vector<int> pos, int row, int n){
        if(n == row){
            vec.push_back(fillBoard(pos, n));
            return;
        }
        for(int col=0; col<n; col++){
            bool foundSafe=true;
            for(int q = 0; q<row; q++){
                if(q == row || pos[q] == col || q+pos[q] == row+col 
                  || q-pos[q] == row-col){
                    foundSafe=false;
                    break; 
                }
            }
            if(foundSafe){
                pos[row] = col;
                NQueensUtil(vec, pos, row+1, n);
                pos[row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n);
        NQueensUtil(ans, pos, 0, n);
        return ans;
    }
};