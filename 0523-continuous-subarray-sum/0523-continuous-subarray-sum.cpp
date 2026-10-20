class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> mpp;

        mpp[0] = -1;

        int pf = 0;

        for(int i=0; i<n; i++){
            pf+=nums[i];

            int rem = pf%k;

            if(mpp.find(rem) != mpp.end()){
                if(i-mpp[rem] >= 2) return true;
            } 

            else mpp[rem] = i;
        }

        return false;

    }
};