class Solution {
public:
    
    int lra(vector<int>& heights) {

    int n = heights.size();
    stack<int> st;
    int maxi = 0;

    for(int i = 0; i <= n; i++) {

        while(!st.empty() &&
              (i == n || heights[st.top()] >= heights[i])) {

            int h = heights[st.top()];
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            int nse = i;

            int width = nse - pse - 1;

            maxi = max(maxi, h * width);
        }

        st.push(i);
    }

    return maxi;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n, 0);

        int max_ar = 0;
        for(int i=0; i<m; i++){
            for(int j=0 ;j<n ;j++){
               if(matrix[i][j]=='1') dp[j]++;
               else dp[j]=0;
            }
            max_ar = max(max_ar, lra(dp));
        }
        return max_ar;
    }
};