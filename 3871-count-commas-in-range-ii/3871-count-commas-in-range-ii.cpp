class Solution {
public:

    long long f(long long a, long long n){
        if(n==0) return 1;
        long long h = f(a, n/2);
        long long d = h*h;
        if(n%2 == 1) return a*d;
        return d;
    }

    long long countCommas(long long n) {

        vector<long long> dp(16, 0);
        // Base cases (default)
        int mul = 1;
        for (int i = 4; i <= 15; i++) {
            // increse happen when no. of digits -> 7, 10, 13, ...
            //Indian Style when no of digits -> 6, 8, 10, ...
            if (i%3==1 && i!=4){
                mul++;
            }
            int a = i;
            int b = i - 1;
        
            dp[i] = (f(10, a) - 1 - f(10, b) + 1) * mul + dp[i - 1];
        } // Print dp


        int digits = to_string(n).size();

        // all ans
        long long ans = dp[digits];

       // 
        long long start = f(10, digits - 1);

        long long commasPerNumber = (digits - 1) / 3;

        ans = dp[digits - 1];

        ans += (n - start + 1) * commasPerNumber;

        
        
        return ans;
    }
};