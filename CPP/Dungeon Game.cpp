class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(), m=dungeon[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = dungeon[n-1][m-1] > 0 ? 1 : abs(dungeon[n-1][m-1])+1;
        for(int i=n-2; i>=0; i--) dp[i][m-1]=max(dp[i+1][m-1] - dungeon[i][m-1], 1);
        for(int i=m-2; i>=0; i--) dp[n-1][i]=max(dp[n-1][i+1] - dungeon[n-1][i], 1);  
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int min_points=min(dp[i+1][j], dp[i][j+1]);
                dp[i][j]=max(min_points - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};