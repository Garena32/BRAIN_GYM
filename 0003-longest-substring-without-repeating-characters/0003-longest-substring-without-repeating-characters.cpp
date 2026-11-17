class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        
        int l = 0;
        vector<int> hash(256, -1);
        int ans = 0;
        for(int r=0; r < s.length(); r++){
            if(hash[s[r]]!=-1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            ans = max(ans, r-l+1);
            hash[s[r]]=r;
        }
        return ans;
    }
};