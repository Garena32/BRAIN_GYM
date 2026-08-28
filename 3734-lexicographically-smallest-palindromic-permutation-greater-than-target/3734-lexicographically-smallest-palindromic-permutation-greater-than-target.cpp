class Solution {
public:

    string res = "";

    bool f(string &curr, vector<int> &mpp, string &target, int &half_len, int i, char &mid, bool isGreater) {
        if(curr.size() == half_len) {
            string rem_l = curr;
            string rem_r = curr;
            reverse(rem_r.begin(), rem_r.end());
            if(mid!='#') rem_l+=mid;
            rem_l += rem_r;
            if(rem_l > target) {
                res = rem_l;
                return true;
            }
            return false;
        }
        for(char ch='a'; ch<='z'; ch++){

            if(mpp[ch-'a'] == 0) continue;
            
            if(!isGreater && ch < target[i]) continue;


            bool curr_scene = isGreater || ch > target[i];

            curr.push_back(ch);
            mpp[ch-'a']--;

            if(f(curr, mpp, target, half_len, i+1, mid, curr_scene)) return true;

            curr.pop_back();
            mpp[ch-'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> mpp(26, 0);
        for(char c : s) mpp[c-'a']++;
        int oc = 0;
        char mid = '#';
        for(int i=0; i<26; i++){
            if(mpp[i]%2==1) {
                oc++;
                mid = i+'a';
            }
        }
        if(oc > 1) return "";

        int half_len = 0;
        for(int i=0; i<26; i++) {
            half_len += mpp[i]/2;
            mpp[i]/=2;
        }

        string curr;

        f(curr, mpp, target, half_len, 0, mid, false);

        return res;
    }
};