class Solution {
public:

    int f(vector<vector<int>> &item, int bget, int i, int n, vector<vector<int>> &dp, vector<int> &inventory){
        if(i==n) return 0;

        if(dp[i][bget]!=-1) return dp[i][bget];

        
        dp[i][bget] = f(item, bget, i+1, n, dp, inventory);

        int price = item[i][1];

        for(int curn=1; curn*price <= bget; curn++){
            dp[i][bget] = max(dp[i][bget], curn+inventory[i]+f(item, bget-curn*price, i+1, n, dp, inventory));
        }

        return dp[i][bget];
        
    }
    
    int maximumSaleItems(vector<vector<int>>& item, int budget) {
        int n = item.size();

        vector<int> inventory(n, 0);

        for(int i=0; i<n; i++){
            int f1 = item[i][0];
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int f2 = item[j][0];

                if(f2%f1==0) inventory[i]++;
            }
        }

       vector<int> dp(budget+1, 0);

        for(int i=0; i<n; i++){
            int p = item[i][1];
            vector<int> dp2 = dp;

            for(int b=p; b<=budget; b++){
                dp2[b] = max(dp2[b], dp[b-p]+inventory[i]+1);
            }

            for(int b=p; b<=budget; b++){
                dp2[b] = max(dp2[b], dp2[b-p]+1);
            }

            dp.swap(dp2);
        }

        return *max_element(dp.begin(), dp.end());

    }
};