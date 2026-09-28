class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char> sat;
        int ans = 0;
        //sat.push(s[0]);
        for(int i=0; i<n; i++){
            int sz = sat.size();
            ans = max(ans, sz);
            if(!sat.empty() && sat.top() == '(' && s[i] == ')') sat.pop();
            else if(s[i] == ')') sat.push(s[i]);
            else if(s[i] == '(') sat.push(s[i]);

        }
        return ans;
    }
};