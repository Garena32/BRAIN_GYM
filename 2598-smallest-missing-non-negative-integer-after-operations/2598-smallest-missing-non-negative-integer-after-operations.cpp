class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        
        int n = nums.size();
        int maxi = INT_MIN;
        // sort(nums.begin(), nums.end());
        // map<int, int> mpp;
        // for(int ele : nums) mpp[ele]++;

        if(val == 1) return nums.size();

        vector<int> buck(val);

        for(int ele : nums) {
            maxi = max(maxi, ele);
            int x = abs(ele)%val;
            if(ele<0 && x!=0) buck[val-x]++;
            else buck[x]++;
        }

        for(int k=0; k<=1e9; k++){
           int i =  k%val;
           // cout << i << " " << buck[i] << "\n";
           // if(mpp[k] > 0 && buck[k%val] > 0) {
            //    buck[k%val]--;
          //  }
            if(buck[i] == 0) return k;
            else {
                buck[i]--;
            }
        }
        return nums.back()+1;
    }
};