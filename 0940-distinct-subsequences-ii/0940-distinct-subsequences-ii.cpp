class Solution {
public:

    int MOD = 1e9+7;

    int distinctSubseqII(string s) {
        
        int n = s.size();

        // total subse of a string of size i is 2*(i-1)th string (including duplicates)

        vector<long long> dp(n+1, 0);
        // dp[i] represents no of unique subse of i-th size string

        vector<long long> last_seen(26, 0);
        // tot unique subse just before the prev occurnece of char 

        // base cases : 
        dp[0] = 1; // including empty subsequence

        for(int i=1; i<=n; i++){

            char l = s[i-1];
            // deafult tot subsequence
            if(last_seen[l-'a'] == 0) dp[i] = (2*dp[i-1]);

            else dp[i] = ((2*dp[i-1]) - (last_seen[l-'a'])+MOD)%MOD;

            last_seen[l-'a'] = (dp[i-1]);

        }
        return (dp[n]-1+MOD)%MOD;
    }
};

 
// aba -> [a->{[], a}], [b->{[], a, b, ab}] [a->{[], a, b, a, ab, ba, aa, aba}]