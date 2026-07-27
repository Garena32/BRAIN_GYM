class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int ele : nums){
            mpp[ele]++;
        }
        for(auto it : mpp){
            if(it.second == 1) return it.first;
        }
        return -1;
    }
};