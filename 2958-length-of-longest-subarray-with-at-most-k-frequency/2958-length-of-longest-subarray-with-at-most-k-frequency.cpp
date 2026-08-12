class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();

        map<int, int> mpp;
        int len = 1;
        int l = 0, r = 0;

        while(l<n && r<n){

           
            
            while(r<n){
                mpp[nums[r]]++;
                if(mpp[nums[r]] > k) break;
                len = max(len, r-l+1);
                r++;
            }

           // cout<<l<<" "<<r<<"\n";

            while(l<n && r<n){
                if(mpp[nums[r]] <= k) break;
                mpp[nums[l]]--;
                l++;
            }

            r++;
           
        }
        return len;
    }
};