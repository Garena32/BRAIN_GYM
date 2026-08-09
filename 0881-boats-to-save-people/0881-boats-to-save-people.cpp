class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int s = 0, e = n-1;

        int cs = 0, count = 0;

        int ctn = 0;


        while(s<=e){
            while(e>0 && cs+nums[e] <= limit && ctn<2) {
                cs += nums[e];
                e--;
                ctn++;
            }
            while(s<n && cs+nums[s] <= limit && ctn<2) {
                cs += nums[s];
                s++;
                ctn++;
            }
            count++;
            cs = 0;
            ctn=0;
        }

        // cs = 0;
        // int count2 = 0;

        // int i = 0;

        // while(i<n){
        //     while(i<n && cs + nums[i] <= limit){
        //         cs += nums[i];
        //         i++;
        //     }
        //     count2++;
        //     cs = 0;
        // }

        // int count3 = 0;
        // cs = 0, i = n-1;
        // while(i>=0){
        //     while(i>=0 && cs + nums[i] <= limit) {
        //         cs += nums[i];
        //         i--;
        //     }
        //     count3++;
        //     cs = 0;
        // }

        return count;
    }
};

// 1 2 4 5