class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 1;
        while(l<=r && l<n && r<n){
            int p = l;
            r = l+1;
            if(r<n && nums[r] > nums[l]){
                while(r<n && nums[r]>nums[l]) {
                    r++;
                    l++;
                }
                ans = max(ans, r-p);
            } else {
                while(r<n && nums[r]<nums[l]) {
                    r++;
                    l++;
                }
                ans = max(ans, r-p);
            }
            // cout << l << " " << r << " " << p << "<->";
            l=p+1;
            r=l;
            // cout << l << " " << r << " " << p << endl;;
        }
        return ans;
    }
};