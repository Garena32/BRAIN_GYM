class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;
        int n = servers.size(), m = tasks.size();

        vector<int> ans;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > ideal;

        priority_queue<
            tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>
        > busy;

        for (int i = 0; i < n; i++) {
            ideal.push({servers[i], i});
        }

        for (int i = 0; i < m; i++) {
            while (!busy.empty() && get<0>(busy.top()) <= i) {
                auto [time, weight, index] = busy.top();
                busy.pop();
                ideal.push({weight, index});
            }

            if (!ideal.empty()) {
                auto [weight, index] = ideal.top();
                ideal.pop();

                ans.push_back(index);
                busy.push({(ll)i + tasks[i], weight, index});
            } else {
                auto [time, weight, index] = busy.top();
                busy.pop();

                ans.push_back(index);
                busy.push({time + tasks[i], weight, index});
            }
        }
        return ans;

    }
};