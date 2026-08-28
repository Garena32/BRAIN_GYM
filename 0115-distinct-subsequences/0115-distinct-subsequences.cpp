class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length();
        int nt = t.length();

        const long long LIMIT = INT_MAX;

        vector<vector<long long>> dp(ns+1, vector<long long>(nt+1, 0));

        // both empty
        dp[0][0] = 1;
        // if t is empty
        for(long long i=0; i<ns+1; i++) dp[i][0] = 1;
        // if s empty ()=>{case considered...}

        for(long long i=1; i<ns+1; i++){
            for(long long j=1; j<nt+1; j++){
                if(s[i-1] == t[j-1]){
                    long long take = dp[i-1][j-1];
                    long long notTake = dp[i-1][j];

                    if (take + notTake > LIMIT ) dp[i][j] = LIMIT;
                    else dp[i][j] = take+notTake;

                } else {
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }
        return dp[ns][nt];
    }
};