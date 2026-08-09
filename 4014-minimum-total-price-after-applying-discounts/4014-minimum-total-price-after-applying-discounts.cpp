class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double cost = 0;

        int ctn = n-1;

        // int x = prices[ctn];

        // cout<<x;

        for(int i=discounts.size()-1; i>=0; i--){
            
            if(ctn < 0) break;

            int p = prices[ctn];
            int d = discounts[i];

            // cout<<p<<" "<<d;

            cost += double(double(p*(100-d)/(double)100));

            // cout<< double(p*(100-d)/(double)100)<<" ";


            ctn--;
        }

        while(ctn>=0){
             cost += (double)prices[ctn];
             ctn--;
        }

        return cost;
        
    }
};