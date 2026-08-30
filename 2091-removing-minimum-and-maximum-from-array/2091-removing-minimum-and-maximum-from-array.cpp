class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int ele : nums) {
            mini = min(mini, ele);
            maxi = max(maxi, ele);
        }
        int ind1 = -1, ind2 = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == mini) ind1 = i;
            if(nums[i] == maxi) ind2 = i;
        }
        // both diff
        int sl = ind1+1;
        int sr = n-ind1;
        int bl = ind2+1;
        int br = n-ind2;

        // cout<<ind1<<" "<<ind2<<endl;
        // cout<<sl<<" "<<sr<<" "<<bl<<" "<<br<<" ";

        

        if(ind1 == ind2) return min(sr, sl);

        int op1 = max(sl, bl);
        
        int op2 = max(sr, br);

        int op3 = min(sl, sr) + min(br, bl);

        // finale !
        return min({op1, op2, op3});
        // both same
    }
};