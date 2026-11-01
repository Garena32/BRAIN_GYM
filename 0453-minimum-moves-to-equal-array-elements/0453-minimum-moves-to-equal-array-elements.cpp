class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0) - (nums.size()*ranges::min(nums));
    }
};

// 2 4 7 9 

// 14 16 14 14  - 7 + 5 + 2