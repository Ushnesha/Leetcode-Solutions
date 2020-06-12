class Solution {
public:
    static 
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, vector<int>>::iterator it;
        //put each diagonal elements in respective vectors
        //elements with i-j value belongs to same diagonal
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                mp[i-j].push_back(mat[i][j]);
        //sort the vectors of each diagonal
        for(it=mp.begin();it!=mp.end();it++){
            sort(it->second.begin(),it->second.end());
        }
        //put back the sorted vectors to the matrix
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                res[i][j]=mp[i-j][0];
                mp[i-j].erase(mp[i-j].begin());
            }
        }
        return res;
    }
};