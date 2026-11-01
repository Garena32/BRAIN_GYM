class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int ele : nums) {
            ans += min(ele%3, 3-ele%3);
            cout << ele%3 << " ";
        }
        
        return ans;
    }
};