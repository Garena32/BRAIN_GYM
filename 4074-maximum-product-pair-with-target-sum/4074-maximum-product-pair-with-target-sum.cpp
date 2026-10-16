class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++) arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());
        vector<pair<pair<int, int>, pair<int, int>>> res;
        int s=0, e=n-1;
        while(s<e){
            int cs = arr[s].first+arr[e].first;
            if(cs == target) {
                pair<int, int> t1 = make_pair(arr[e].first, arr[e].second);
                pair<int, int> t2 = make_pair(arr[s].first, arr[s].second);
                res.push_back({t1, t2});
                s++;
                e--;
            }
            else if(cs > target) e--;
            else s++;
        }

        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        int maxi =  INT_MIN;
        for(auto it : res){
            int a = it.first.first;
            int b = it.second.first;
            int ai = it.first.second;
            int bi = it.second.second;
            if(maxi < a*b && a > b){
                ans[0] = ai;
                ans[1] = bi;
                maxi = a*b;
            }
        }
        return ans;
    }
};