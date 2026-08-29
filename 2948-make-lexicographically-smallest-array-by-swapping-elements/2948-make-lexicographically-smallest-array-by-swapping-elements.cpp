class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        vector<pair<int, int>> t;

        for(int i=0; i<n; i++) t.push_back({nums[i], i});

        sort(t.begin(), t.end());

        int s = 0;

        while(s<n){
            int e = s+1;

            while(e<n && t[e].first-t[e-1].first <= limit) e++;

            vector<int> ind;
            for(int i=s; i<e; i++) ind.push_back(t[i].second);
            sort(ind.begin(), ind.end());

            int sz = ind.size();

            for(int i=0; i<sz; i++){
                nums[ind[i]] = t[s+i].first;
            }
            s = e;
        }
        return nums;
    }
};

// [1 2 3 9 8 5] k=3
// [1 2 3 5 8 9]