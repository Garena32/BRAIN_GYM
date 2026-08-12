class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        if(obstacleGrid[0][0]) return 0;

        // base cases : 
        for(int i=0; i<m; i++) {
            if(!obstacleGrid[i][0]) dp[i][0] = 1;
            else break;
        }
        for(int j=0; j<n; j++) {
            if(!obstacleGrid[0][j]) dp[0][j] = 1;
            else break;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++) {

                if(obstacleGrid[i][j]) dp[i][j] = 0;

                else {
                    int p1 = dp[i-1][j];
                    int p2 = dp[i][j-1];
                    dp[i][j] = p1+p2;
                }

                
            }
        }

        return dp[m-1][n-1];
    }
};