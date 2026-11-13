class Solution {
public:
    long long countValidSubstrings(string s) {
        long long total = 0;
        int n = s.size();
        if(n%2==0) total = 1LL*(n/2)*(n+1);
        else total = 1LL*((n+1)/2)*n;
        long long rm = 0;

        bool found = false;
        int l = -1;

        for(int i=2; i<n; i++){
            if(s[i-2]=='a' && s[i-1]=='b' && s[i]=='c'){
                //rm+=i-1;
                found = true;
                l = i-1; 
            }
            if(found){
                rm += l;
            }
        }
        return total - rm;
    }
};

// mpk abc mq