class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int ans = 0;
        int ctn = 0;
        while(i<sz){
            int r = nums[i][0];
            
            vector<int> seats(10);
            while(i<sz && nums[i][0] == r) {
                seats[nums[i][1]-1] = 1;
                i++;
            }
            // for(int ele : seats) cout<<ele<<" ";
            if(!seats[5] && !seats[6] && !seats[7] && !seats[8] && !seats[1] && !seats[2] && !seats[3] && !seats[4]) ans+=2;
            else if (!seats[5] && !seats[6] && !seats[7] && !seats[8]) ans++;
            else if(!seats[1] && !seats[2] && !seats[3] && !seats[4]) ans++;
            else if(!seats[3] && !seats[4] && !seats[5] && !seats[6]) ans++;
            
            ctn++;

            // cout<<"row : "<<r<<" "<<ans<<"\n";

        }
        if(n-ctn > 0) ans += 2*(n-ctn);
        
        return ans;

    } 
};