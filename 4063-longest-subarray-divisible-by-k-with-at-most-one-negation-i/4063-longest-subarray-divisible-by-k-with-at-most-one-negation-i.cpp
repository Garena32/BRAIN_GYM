class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int cs = 0;
            unordered_map<int, int> mpp;
            for(int j=i; j<n; j++){
                cs += nums[j];
                int val = ((2*nums[j])%k+k)%k;
                mpp[val]++;
                if(cs%k == 0) ans = max(ans, j-i+1);
                else {
                    int x = (cs%k+k)%k;
                    if(mpp[x]!=0) ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
