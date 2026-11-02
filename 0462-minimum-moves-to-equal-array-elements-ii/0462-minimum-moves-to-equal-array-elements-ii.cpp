class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        
        if(n%2 == 1) {
            int t = nums[n/2];
            // int ans = 0;
            for(int ele : nums) ans += abs(ele-t);

        } else {
            int a1 = 0;
            int a2 = 0;
            int t1 = -1, t2 = -1;
            t1 = nums[n/2];
            t2 = nums[n/2 - 1];
            for(int ele : nums) a1 += abs(ele-t1);
            for(int ele : nums) a2 += abs(ele-t2);
            ans = min(a1, a2);
        }
        return ans;
    }
};

// 1 2 9 10