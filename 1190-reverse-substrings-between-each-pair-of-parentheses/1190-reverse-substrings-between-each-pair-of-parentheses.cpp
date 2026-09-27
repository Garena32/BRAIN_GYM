class Solution {
public:
    string reverseParentheses(string s) {

        int n = s.size();
        vector<pair<char, int>> t;

        for(int i=0;i<n; i++){
            if(s[i]=='(' || s[i] == ')') t.push_back({s[i], i});
        }

        stack<pair<char, int>> st;
        for(auto c : t){
            if(c.first == '(') st.push({c.first, c.second});
            else {
                int strt = st.top().second;
                int end = c.second;
                reverse(s.begin()+strt+1, s.begin()+end);
                st.pop();
            }
        }
        string res = "";
        for(char c : s){
            if(!(c=='(' || c==')')) res+=c;
        }
        return res;
    }
};