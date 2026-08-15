class Solution {
public:
  
    int f(int i, int j, string word1, string word2){

        int n1 = word1.size(); 
        int n2 = word2.size();

        if(i==n1 && j==n2) return 0;
        else if(i==n1) return n2-j;
        else if(j==n2) return n1-i;


        if(word1[i] == word2[j]){
            return f(i+1, j+1, word1, word2);
        }

            int p1 = 1+f(i+1, j, word1, word2);
            int p2 = 1+f(i, j+1, word1, word2);
            int p3 = 1+f(i+1, j+1, word1, word2);
            return min({p1, p2, p3});

    }

    int minDistance(string word1, string word2) {
        // return f(0, 0, word1, word2);

        int n1 = word1.size();
        int n2 = word2.size();

        if(n1 == 0 && n2 == 0) return 0;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        // base cases : 

        for(int i=0; i<=n1; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=n2; i++){
            dp[0][i] = i;
        }

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }



        return dp[n1][n2];

    }
};