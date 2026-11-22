class Solution {
public:
    int minRange(int a, int b, int c) {
        int mini = min({a, b, c});
        int maxi = max({a, b, c});

        int op1 = maxi - mini;
        int op2 =  (a+b+c - maxi)-mini;
        int op3 =  (a+b+c - mini)-maxi;

        // cout << op1 << " " << op2 << " " << op3;
return min({op1, op2, op3});
    }
};