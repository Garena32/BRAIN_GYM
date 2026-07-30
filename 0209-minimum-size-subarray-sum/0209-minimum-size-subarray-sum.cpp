class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cs = 0;
        int ans = 1e9;
        int l = 0, r = 0;
        while(l < n && r < n) {
            while(r<n && cs < target){
                cs += nums[r];
                r++;
            }
           
            while(l < n && cs >= target){
                ans = min(ans, r-l+1);
                cs -= nums[l];
                l++; 
            }
        }
        return (ans == 1e9) ? 0 : ans-1;
    }
};