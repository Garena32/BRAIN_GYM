class Solution {
public:

   int solve(vector<int>& coins, int amount, int i){

    if(amount == 0) return 0;
    if(i==0){
        if((amount % coins[i]) == 0) return amount/coins[i];
        else return 1e9;
    }

    int p1 = 1e9, p2 = 1e9;
    p1 = solve(coins, amount, i-1);
    if(coins[i] <= amount) p2 = 1 + solve(coins, amount-coins[i], i);

    return min(p1, p2);
   }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = solve(coins, amount, n-1);
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int p1 = 1e9, p2 = 1e9;
                p1 = dp[i-1][j];
                if(coins[i] <= j) p2 = 1 + dp[i][j-coins[i]];
                
                dp[i][j] = min(p1, p2);
            }
        }

        int ans = dp[n-1][amount];

        if(ans == 1e9) return -1;
        return ans;
    }
};