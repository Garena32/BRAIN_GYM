class Solution {
public:


    bool ck(int n, int f){
        int x = 1;
        while(n!=0){
            x *= n % 10;
            n /= 10;
        }
        //cout << x%f;
        
        return x % f == 0;
    }
    
    int smallestNumber(int n, int t) {
       for(int i=n; i<=n+10; i++){
           if(ck(i, t)) {
               return i;
           }
       }

        return 404;
        
    }
};