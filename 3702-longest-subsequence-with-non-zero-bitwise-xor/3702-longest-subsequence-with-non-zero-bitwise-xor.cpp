class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size(), x=0;
        bool az = true;

        if(n==1){
            if(nums.back() == 0) return 0;
            else return 1;
        }

        for(int i=1; i<n; i++){
            if(!(nums[i-1] == nums[i] && nums[i]==0)){
                az = false;
                break;
            }
        }
        if(az) return 0;

        for(int ele : nums) x ^= ele;
        return (x==0) ? n-1 : n;
    }
};