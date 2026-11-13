class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        
        int n = gas.size();
        int cg = 0;
        int a = 0;

        int tg = 0, tc = 0;
        for(int ele : gas) tg += ele;
        for(int ele : cost) tc += ele;

        for(int i=0; i<n; i++){
            cg += gas[i]-cost[i];
            if(cg < 0){
                a = i+1;
                cg = 0;
            }
        }
        if(tc > tg) return -1;
        return a;
    }
};