class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(), arrays.end());
        int m = arrays.size();
        vector<vector<int>> nums;
        for(auto it : arrays){
            if(it.size() == 1) nums.push_back({it[0], it[0]});
            else nums.push_back({it[0], it.back()});
        }

        for(int i=0; i<m; i++){
            cout<<nums[i][0]<<" "<<nums[i][1]<<"\n";
        }

        int a1 = nums[0][0], a2 = nums[0][1];
        int maxi = INT_MIN;
        int ctn = 0;
        for(int i=1; i<m; i++){
            maxi = max(maxi, abs(a1-nums[i][1]));
        }
        for(int i=1; i<m; i++){
            maxi = max(maxi, abs(a2-nums[i][0]));
        }

        return maxi;
    }
};