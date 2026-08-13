class Solution {
public:
int solve(vector<int>& nums, int target, int i) {
    if (i == nums.size())
        return target == 0;

    int plus = solve(nums, target - nums[i], i + 1);
    int minus = solve(nums, target + nums[i], i + 1);

    return plus + minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solve(nums, target, 0);
        return ans;
    }
};