class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base cases :
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++) {
                int p1 = dp[i-1][j];
                int p2 = dp[i][j-1];

                dp[i][j] = p1+p2;
            }
        }
        return dp[m-1][n-1];
    }
};