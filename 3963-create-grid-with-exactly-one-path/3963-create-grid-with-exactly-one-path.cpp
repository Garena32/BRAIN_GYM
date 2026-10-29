class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;

        string s = "";
        for(int i=0; i<n; i++) s += '.';
        string t;
        for(int j=0; j<n-1; j++){
            t.push_back('#');
        }
        t.push_back('.');

        cout << s << " ";

        

        res.push_back(s);
        
        for(int i=1; i<m; i++) res.push_back(t);

         cout << res[0] << " ";

        for(int i=0; i<m; i++) {
            cout << res[i] << endl;
        }

        return res;
        
    }
    
};