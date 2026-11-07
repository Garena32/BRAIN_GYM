class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;
        int n = servers.size(), m = tasks.size();

        vector<int> ans;
        ans.reserve(m);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > heapsmol;

        priority_queue<
            tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>
        > heaplarge;

        for (int i = 0; i < n; i++) {
            heapsmol.push({servers[i], i});
        }

        for (int i = 0; i < m; i++) {
            while (!heaplarge.empty() && get<0>(heaplarge.top()) <= i) {
                auto [time, weight, index] = heaplarge.top();
                heaplarge.pop();
                heapsmol.push({weight, index});
            }

            if (!heapsmol.empty()) {
                auto [weight, index] = heapsmol.top();
                heapsmol.pop();

                ans.push_back(index);
                heaplarge.push({(ll)i + tasks[i], weight, index});
            } else {
                auto [time, weight, index] = heaplarge.top();
                heaplarge.pop();

                ans.push_back(index);
                heaplarge.push({time + tasks[i], weight, index});
            }
        }
        return ans;

    }
};