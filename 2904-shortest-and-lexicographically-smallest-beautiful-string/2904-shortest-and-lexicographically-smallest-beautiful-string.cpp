class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> t;
        int n = s.length();
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=i; j<n; j++){
                str += s[j];
                if(j-i+1 >= k){
                    int ctn = 0;
                    for(int m=i; m<=j; m++){
                        if(s[m] == '1') ctn++;
                    }
                    if(ctn == k) t.push_back(str);
                }
            }
        }

        int count = 0;
        for(char c : s) {
            if(c == '1') count++;
        }

        int mini = INT_MAX;

        for(int i=0; i<t.size(); i++) {
            // cout<<t[i]<<" "<<t[i].size()<<" ";
            int sz = t[i].size();
            mini = min(mini, sz);
        }


        cout<<mini<<endl;

        vector<string> filter;
        for(string ele : t){
            if(ele.size() == mini){
                filter.push_back(ele);
                // cout<<ele<<" ";
            }
        }



        // if(k == 1 && count>0) return "1";

        sort(filter.begin(), filter.end());

        string res = (filter.size()>0) ? filter[0] : "";

        // res filter
        int strt = 0, e = res.size()-1;
            while(strt<e && res[strt] == '0') strt++;
            while(e>0 && res[e] == '0') e--;
        string f = "";
        for(int i=strt; i<=e; i++) f+=res[i];
        

        

        // cout<<res;

        return f;
    }
};