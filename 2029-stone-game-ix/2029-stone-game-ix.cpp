class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // int n = stones.size();
        // if(n==1) return false;

        // map<int, vector<int>> mpp;
        // for(int ele : stones){
        //     int key = ele%3;
        //     mpp[key].push_back(ele);
        // }


        // int c1 = mpp[1].size();
        // int c2 = mpp[2].size();
        // int c0 = mpp[0].size();

        // int cs = 0;
        // if(c2>0) {
        //     cs+=mpp[2].back();
        //     mpp[2].pop_back();
        //     c2--;
        // }
        // else if(c1) {
        //     cs+=mpp[1].back();
        //     mpp[1].pop_back();
        //     c1--;
        // } else {
        //     return false;
        // }

        // int turn = 1;

        // while(true){
        //     int rem = 3 - cs%3;
        //     if(!c0 && !c1 && !c2 && rem!=3) return false; 
        //     if(rem == 3 && turn%2 == 0) return false; 
        //     if(rem == 3 && turn%2 == 1) return true;

        //     if(rem == 1){
        //         if(c2){
        //             cs += mpp[2].back();
        //             mpp[2].pop_back();
        //             c2--;
        //             turn++;
        //         } else if(c0){
        //             cs += mpp[0].back();
        //             mpp[0].pop_back();
        //             c0--;
        //             turn++;
        //         } else return !(turn%2 == 0);
        //     } 

        //     if(rem == 2){
        //         if(c1){
        //             cs += mpp[1].back();
        //             mpp[1].pop_back();
        //             c1--;
        //             turn++;
        //         } else if(c0){
        //             cs += mpp[0].back();
        //             mpp[0].pop_back();
        //             c0--;
        //             turn++;
        //         } else return !(turn%2 == 0);
        //     } 

        // }
        // return false;



        int c0 = 0, c1 = 0, c2 = 0;

        for (int x : stones) {
            if (x % 3 == 0) c0++;
            else if (x % 3 == 1) c1++;
            else c2++;
        }

        if (c1 == 0 && c2 == 0)
            return false;

        // If c0 is even, Alice wins if either side has
        // enough stones to create the required alternating pattern.
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }

        // If c0 is odd, Alice can win when one side has
        // at least 2 more stones than the other.
        return abs(c1 - c2) > 2;
    }
};

// A B A B 
// A B A

// 2 1 1
// nums[i]%3 => 0, 1, 2

// 0 : 3
// 1 : 1 4
// 2 : 5 2 


// 0 : 3
// 1 : 
// 2 : 2 2
