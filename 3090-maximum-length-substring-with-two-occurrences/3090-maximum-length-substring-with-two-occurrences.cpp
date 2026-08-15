class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0, j=0, l = 0;
        vector<int> mpp(26);
        while(i<n && j<n){

            

            while(j<n){
                mpp[s[j]-'a']++;
                if(mpp[s[j]-'a'] >= 3) break;
                l = max(l, j-i+1);
                
                j++;
            }

            // cout<<i<<" "<<j<<endl;
            
            while(i<n && j<n){
                mpp[s[i]-'a']--;
                i++;
                if(mpp[s[j]-'a'] <= 2) break;
            }

            j++;
            
        }
        return l;
    }
};