class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 0;
        for(int i=0; i<n; i++){

            int pf = 0;
            int rem = nums[i]%k;

            for(int j=i; j<n; j++){

                pf+=nums[j];

                if(rem != nums[j]%k) break;

                if(pf%k == rem) m = max(m, j-i+1);

            }
        }
        return m;
    }
};