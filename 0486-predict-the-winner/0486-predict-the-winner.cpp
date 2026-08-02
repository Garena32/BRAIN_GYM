class Solution {
public:

    bool f (int s, int e, int ctn, int s1, int s2, vector<int> &nums) {
        if(s > e) return s1 >= s2;

        cout << s1 << " " << s2 << endl;

        if(ctn%2 == 0) {
            return f(s+1, e, ctn+1, s1 + nums[s], s2, nums) || f(s, e-1, ctn+1, s1 + nums[e], s2, nums);

        } 
        
        return f(s+1, e, ctn+1, s1, s2 + nums[s], nums) && f(s, e-1, ctn+1, s1, s2 + nums[e], nums);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2 == 0) return true;
        
        return f(0, n-1, 0, 0, 0, nums);
    }
};

// 