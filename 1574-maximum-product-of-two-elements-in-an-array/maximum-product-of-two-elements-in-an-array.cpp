class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = -1, maxi2 = -1;

        for(int ele : nums){
            if(ele > maxi) {
                maxi2 = maxi;
                maxi = ele;
            } else if(ele > maxi2){
                maxi2 = ele;
            }
        }
        return (maxi-1)*(maxi2-1);
    }
};