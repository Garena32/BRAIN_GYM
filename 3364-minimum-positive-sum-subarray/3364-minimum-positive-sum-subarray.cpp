class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int a = INT_MAX;
        for(int len=l; len<=r; len++){

            // cout << len << "\n";

            int i = 0;
            int j = len-1;

            int cs = 0;

            for(int k=i; k<=j; k++) cs += nums[k];

            if(cs > 0) a = min(a, cs);

            // cout << a << " " << cs << endl;

            while(i<n && j<n){
                cs -= nums[i];
                i++;
                j++;
                if(j<n) cs += nums[j];
                if(cs > 0 && j<n && j-i+1==len) {
                    a = min(a, cs);
                    // cout << i << " " << j << endl;
                }
            }

            // cout <<"Final : "<< a << "\n";
        }
        return (a==INT_MAX) ? -1 : a;
    }
};