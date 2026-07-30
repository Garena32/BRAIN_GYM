class Solution {
public:
    int minimumPushes(string word) {
      
        int sz = word.length();
        
        int n = sz/8;
        int rem =sz%8;

        int sum = (n*(n+1))/2;

        return sum*8 + (n+1)*rem;
    }
};