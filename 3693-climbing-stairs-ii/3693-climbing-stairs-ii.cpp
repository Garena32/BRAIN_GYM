class Solution {
public:

    int f(int i, int n, vector<int> &costs){

        if(i==n) return 0;

        int a = INT_MAX, b = INT_MAX, c = INT_MAX;

        if(i+1<=n) a = costs[i]+1+f(i+1, n, costs);
        if(i+2<=n) b = costs[i+1]+4+f(i+2, n, costs);
        if(i+3<=n) c = costs[i+2]+9+f(i+3, n, costs);

        return min({a, b, c});
    }

    int climbStairs(int n, vector<int>& costs) {

        // return f(0, n, costs);
        
        vector<int> dp(n+1, 0);

        // base case : 
        dp[n] = 0;

        for(int i=n-1; i>=0; i--){
            int a=INT_MAX, b=INT_MAX, c=INT_MAX;
            if(i+1<=n){
                a = costs[i] + (1) + dp[i+1];
            } 
            if(i+2<=n){
                b = costs[i+1] + 4 + dp[i+2];
            }
            if(i+3<=n){
                c = costs[i+2]+ 9 + dp[i+3];
            }

            dp[i] = min({a, b, c});
        }
        return dp[0];
    }
};