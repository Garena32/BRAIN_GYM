class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mpp;

        for(auto it : knowledge){
            mpp[it[0]] = it[1];
        }

        int n = s.size();

        string res = "";

        for(int i=0; i<n; i++){

            string t = "";
            
            if(s[i] == '('){
                int j = i+1;
                while(j<n && s[j] != ')'){
                    t+=s[j];
                    j++;
                }
                i = j;
                if(mpp.find(t)!=mpp.end()) res += mpp[t];
                else res += '?';
            }

            else res += s[i];

        }
        return res;
    }
};