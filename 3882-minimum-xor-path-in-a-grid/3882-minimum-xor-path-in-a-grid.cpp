class Solution {
public:

    int solve(vector<vector<int>> &grid, int i, int j, int curr_xor, vector<vector<vector<int>>> &dp){

        int m = grid.size(), n = grid[0].size();

        if(i==m-1 && j==n-1) return grid[i][j] ^ curr_xor;

        if(dp[i][j][curr_xor]!=-1) return dp[i][j][curr_xor];

        int r = INT_MAX, d = INT_MAX;
            
        if(j+1 < n) r = solve(grid, i, j+1, grid[i][j] ^ curr_xor, dp);
        if(i+1 < m) d = solve(grid, i+1, j, grid[i][j] ^ curr_xor, dp);

        return dp[i][j][curr_xor]= min(r, d);
    }
     
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        int i = 0, j = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return solve(grid, i, j, 0, dp);
    }
};