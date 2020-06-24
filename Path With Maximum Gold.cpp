class Solution {
public:
    int getMaxPath(int p, int q, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int up=0, down=0, left=0, right=0;
        if(p<0 || q<0 || p>=grid.size() || q>=grid[0].size() || vis[p][q]==1 || grid[p][q]==0) 
            return 0;
        vis[p][q]=1;
        up= getMaxPath(p-1,q,vis,grid);
        down = getMaxPath(p+1,q,vis,grid);
        left= getMaxPath(p,q-1,vis,grid);
        right= getMaxPath(p,q+1,vis,grid);
        vis[p][q]=0;
        return grid[p][q]+max(up,max(down,max(left,right)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_path=0, n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                vector<vector<int>> vis(n , vector<int>(m,0));
                max_path=max(max_path, getMaxPath(i,j,vis,grid));
            }
        }
        return max_path;
    }
};