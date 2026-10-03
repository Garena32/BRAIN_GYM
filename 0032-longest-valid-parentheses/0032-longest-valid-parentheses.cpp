class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        // vector<int> oc(n), cc(n);
        // oc[0] = (s[0] == '(') ? 1 : 0;
        // cc[0] = (s[0] == ')') ? 1 : 0;
        // for(int i=1; i<n; i++) {
        //     int x = (s[i] == '(') ? 1 : 0;
        //     int y = (s[i] == ')') ? 1 : 0;
        //     oc[i] = oc[i-1] + x;
        //     cc[i] = cc[i-1] + y;
        // }
        int ans = 0;
        for(int i=0; i<n; i++){
            int cs = 0;
            stack<char> st;
            for(int j=i; j<n; j++){
                if(!st.empty() && st.top() == '(' && s[j] == ')') {
                    st.pop();
                    // cout << "pop ";
                }
                else {
                    st.push(s[j]);
                    // cout << "push ";
                }
                if(s[j] == '(') cs++;
                else cs--;
                // cout << cs << " " << st.size() << " ";
                if(cs == 0 && st.size() == 0) ans = max(ans, j-i+1);
            }
            if(cs == n) break;
            cout << "\n";
        }
        return ans;
    }
};