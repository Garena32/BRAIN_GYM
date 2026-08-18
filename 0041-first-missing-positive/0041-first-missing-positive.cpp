class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        int mini =  INT_MAX;
        int maxi = INT_MIN;

        map<int, int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]] = 1;
            if(nums[i] > 0 && nums[i] < mini) mini = nums[i];
            if(nums[i] > 0 && nums[i] > maxi) maxi = nums[i];
        }

        // mini is neg 
        if(mini <= 0 || mini > 1) return 1;
        // mini > 0

        for(int i=mini; i<=maxi; i++){
            if(!mpp[i]) return i;
        }

       return maxi+1; 

    }
};