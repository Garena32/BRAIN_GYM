class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = -1, min_dist = INT_MAX, ctn = 0;
        for(auto it : drones){
            int dist = abs(it[0]-target[0]) + abs(it[1]-target[1]);
            if(it[2] >= dist && dist < min_dist){
                min_dist = dist;
                mini = ctn;
            }
            ctn++;
        }
        return mini;
    }
};