class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pf(n, 0);
        pf[0] = stones[0];
        for(int i=1; i<n; i++) pf[i] = pf[i-1]+stones[i];
        vector<int> dp(n, 0);
        dp[n-1] = pf[n-1];
        for(int i=n-2; i>=1; i--){
            int t = pf[i] - dp[i+1];
            int s = dp[i+1];
            dp[i] = max(t, s);
        }
        return dp[1];
    }
};

// 0 -1 1 -2 2 -3
// 0 1 2 3 4 5 6