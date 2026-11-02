class Solution {
public:
    double f(string s, string d,
             unordered_map<string, vector<pair<string, double>>>& adj) {

        // double res = 1.0;

        map<string, int> visi;
        queue<pair<string, double>> q;
        q.push({s, 1.0});
        visi[s] = 1;
        while (!q.empty()) {
            auto it = q.front();
            string node = it.first;
            double cw = it.second;
            q.pop();
            for (auto it : adj[node]) {
                string adjN = it.first;
                double w = it.second;
                if (!visi[adjN]) {
                    double val = cw * w;
                    q.push({adjN, val});
                    visi[adjN ] = 1;
                    if (adjN == d)
                        return val;
                }
            }
        }
        return -1.00;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();

        unordered_map<string, vector<pair<string, double>>> adj;

        map<string, int> mpp;

        vector<double> ans;

        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];

            double w = values[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0 / w});
            mpp[v]++;
            mpp[u]++;
        }

        for (auto q : queries) {
            string s = q[0];
            string d = q[1];

            if (mpp.find(d) == mpp.end() || mpp.find(s) == mpp.end())
                ans.push_back(-1.0);
            else {
                if (s == d)
                    ans.push_back(1.0);
                else {
                    double val = f(s, d, adj);
                    cout << val << " ";
                    ans.push_back(val);
                }
            }
        }

        return ans;
    }
};