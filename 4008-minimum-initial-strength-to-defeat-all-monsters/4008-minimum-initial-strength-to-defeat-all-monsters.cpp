class Solution {
public:
    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> bonus(n+1, 0), diff(n+1, 0);
        
        // int sz = boosts.size();

        // using DAT
        for (auto it : boosts) {
            int l = it[0];
            int r = it[1];
            long long val = it[2];

            diff[l] += val;
            diff[r+1] += (-val);
        }

        long long curr = 0;

        for(int i=0; i<n+1; i++){
            curr += diff[i];
            bonus[i] = curr;

           // cout << bonus[i] << " ";
        }

        // long long acc = accumulate(monsters.begin(), monsters.end(), 0);

        long long acc = 0;

        for(int ele : monsters) acc += ele;


        // Apply BS 
        long long low = 0;
        long long high = acc;

        long long ans = 0;

        while(low <= high) {
            long long mid = low + (high-low)/2;

            long long track = mid;

            bool poss = true;

            for(int i=0; i<n; i++) {

                if(track + bonus[i] < monsters[i]){
                    poss = false;
                    break;
                }

                track -= monsters[i];

                if(track < 0) track = 0; 
                
            }

            if(poss) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};