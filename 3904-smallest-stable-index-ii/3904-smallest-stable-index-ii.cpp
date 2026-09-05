class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> sm(n), pm(n);

        pm[0] = nums[0];
        for(int i=1; i<n; i++) {
            pm[i] = max(pm[i-1], nums[i]);
        }
        // for(int i=0; i<n; i++) cout << pm[i] << " ";

        sm[n-1] = nums.back();
        for(int i=n-2; i>=0; i--){
            sm[i] = min(sm[i+1], nums[i]);
        }
        // cout << "\n";
        // for(int i=0; i<n; i++) cout << sm[i] << " ";
        
        

        for(int i=0; i<n; i++){
            if(pm[i]-sm[i] <= k) return i;
        }
    
        return -1;

    }
};