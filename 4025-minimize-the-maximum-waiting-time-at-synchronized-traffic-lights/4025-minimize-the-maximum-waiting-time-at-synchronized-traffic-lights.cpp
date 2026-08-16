class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ans = 0;
        sort(lights.begin(), lights.end());
        for(int ele : arrivalTime){
            int r = ele % period;
            if(r < lights.back()) ans += 0;
            else {
               ans = max(ans, period-r);
            //    cout<<period-r;
            }
        }
        return ans;
    }
};