class Solution {
public:
    vector<string> largestString(vector<int>& nums) {

        int n = nums.size();

        vector<string> res;

        vector<char> store(32);
        for(int i=0; i<32; i++){
            if(i>=0 && i<=25) store[i] = i+'a';
            else store[i] = 'z';
        }

        // for(int i=0; i<32; i++) cout<<store[i]<<" ";

        for(int ele : nums){
            string str = bitset<32>(ele).to_string();
            res.push_back(str);
        }

        // for(string s : res) cout<<s<<" ";
// int ctn = 0;
        for(int i=0; i<res.size(); i++){
            string s = res[i];
            string t = "";
            for(int i=31; i>=0; i--){
                if(s[i] == '1'){
                    // cout<<i<<" "<<store[32-i-1];
                    t += store[32-i-1];
                    if(i==5) t+='z';
                }
            }
            // cout<<ctn<<" ";
            reverse(t.begin(), t.end());
            res[i] = t;
        }
        return res;
    }
};