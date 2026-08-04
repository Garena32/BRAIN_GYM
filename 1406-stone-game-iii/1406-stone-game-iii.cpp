class Solution {
public:
    string stoneGameIII(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n+4, 0);

        for(int i=n-1; i>=0; i--) {

            int p1 = -1e9, p2 = -1e9, p3 = -1e9;

            p1 = nums[i] - dp[i+1];
            if(i+1<n) p2 = nums[i]+nums[i+1] - dp[i+2];
            if(i+2<n) p3 = nums[i]+nums[i+1]+nums[i+2] - dp[i+3];

            dp[i] = max({p1, p2, p3});
        }

        int res = dp[0];

        if(res == 0) return "Tie";

        if(res < 0) return "Bob";
        return "Alice";
    }
};