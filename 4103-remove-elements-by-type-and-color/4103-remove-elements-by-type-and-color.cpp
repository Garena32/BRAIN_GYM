class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {

        int n = colors.size();

        vector<pair<pair<int, int>, int>> st;
        for(int i=0; i<n; i++){
            int t = types[i];
            int c = colors[i];

            if(!st.empty() && st.back().first.first==t && st.back().first.second==c) st.back().second++;
            else {
                st.push_back({{t, c}, 1});
                
            }

            if(st.back().second == groupSize[t]){
                st.pop_back();
            }
        }
        
        return st.empty();
    }
};