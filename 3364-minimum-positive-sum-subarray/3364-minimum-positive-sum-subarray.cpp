class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int a = INT_MAX;;
        for(int len=l; len<=r; len++){

            for(int i=0; i<n; i++){
                int cs = 0;
                for(int j=i; j<n; j++){
                    cs += nums[j];
                    if(j-i+1 == len && cs > 0){
                        a = min(a, cs);
                    }
                }
            }
        }
        return (a==INT_MAX) ? -1 : a;
    }
};