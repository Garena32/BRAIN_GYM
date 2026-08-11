class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int cs = nums[0];

        vector<int> mpp(51, 0);

        for(int i=0; i<n; i++) mpp[nums[i]]++;

        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1] != 1){
                break;
            } else {
                cs += nums[i];
            }
        }

        int ans = cs;

        if(ans > 50) return ans;
        else {
            if(mpp[ans] == 0) return ans;
            else {
                while(ans <= 50 && mpp[ans] >= 1) ans++;
                cout << ans;
            }
        }
        return ans;
    }
};

// longest seq len that sum <= ans 
// if same len seq then pick max sum one and find sum <= ans