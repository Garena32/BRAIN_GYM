class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int i = 0, j = n-1;

        string s2 = s;
        reverse(s2.begin(), s2.end());

        // dp[i][j] [0..i] from s and [0...j] from s2;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case : 
        char x = s2[0];
        int idx = 0;
        for(int i=0; i<n; i++){
            if(s[i] == x){
                idx = i;
                break;
            }
        }
        for(int i=idx; i<n; i++) dp[i][0] = 1;

        x = s[0];
        for(int i=0; i<n; i++){
            if(s2[i] == x){
                idx = i;
                break;
            }
        }
        for(int i=idx; i<n; i++) dp[0][i] = 1;

        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(s[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n-1][n-1];

    }
};