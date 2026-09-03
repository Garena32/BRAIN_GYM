class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        int maxi = INT_MIN;
        stack<int> st;

        for(int i=0; i<n; i++){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                maxi = max(maxi, h*(nse-pse-1));
            }

            st.push(i);
        }

        while(!st.empty()){
                int h = heights[st.top()];
                st.pop();
                int nse = n;
                int pse = (st.empty()) ? -1 : st.top();
                maxi = max(maxi, h*(nse-pse-1));
            }
            return maxi;
    }
};