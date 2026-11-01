class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        
        vector<int> pf(n), sf(n);

        pf[0] = nums[0];
        for(int i=1; i<n; i++) pf[i] = max(pf[i-1], nums[i]);

        sf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) sf[i] = min(sf[i+1], nums[i]);

        int count = 0;
        for(int i=0; i<n; i++){
            if(i+1 < n && locked[i] == 1 && nums[i] > sf[i+1]) {
                cout << i << " ";
                count++;
            }
            else if(i-1 >= 0 && locked[i] == 1 && nums[i] < pf[i-1]) {
                cout << i << " ";
                count++;
            }
        }

        cout << count << endl;

        if(count > k) return -1;

        int op = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) {
                if(nums[i] > nums[j]) op++;
            }
        }

        op += count;

        return op;
    }
};

