class Solution {
public:
    int minimumPushes(string word) {

        int n = word.length();
        
        vector<int> mpp(26, -1), freq(26, 0);

        int cn = 1, cnt = 0;

        

        for ( char c : word ) freq[c-'a']++;

        vector<pair<int, char>> nums;

        for(int i=0; i<26; i++){
            if(freq[i] > 0) nums.push_back({freq[i], i+'a'});
        }

        sort(nums.rbegin(), nums.rend());
        
        for(auto it : nums){

            if(cnt == 8) {
                cnt = 0;
                cn++;
            }

            char c = it.second;

            if(mpp[c-'a'] == -1){
                mpp[c-'a'] = cn;
                cnt++;
            } 

            

            
        }

        // for(auto it : nums) cout<<it.first << " " << it.second << "\n";


        int ans = 0;

        for(char c : word) ans += mpp[c-'a'];


        return ans;
    }
};