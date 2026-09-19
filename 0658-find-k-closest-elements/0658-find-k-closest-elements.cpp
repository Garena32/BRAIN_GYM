class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();

        int left = 0;
        int right = n - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (x - nums[mid] > nums[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return vector<int>(nums.begin() + left,
                           nums.begin() + left + k);
    }
};