class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size(),ans;
        priority_queue<int> pq;
        for(int ele : stones) pq.push(ele);
        while(!pq.empty()){
            ans = pq.top();
            pq.pop();
            if(pq.empty()) break;
            int b = pq.top();
            pq.pop();

            ans = ans - b;

            pq.push(ans);
        }
        return ans;
    }
};

// 1 1 2 4 1