class Solution {
public:


    vector<int> f(int n){

        vector<int> res;

        if(n%2 == 0){
            res.push_back(2);
            while(n%2 == 0) n/=2;
        }

        for(int i=3; i*i<=n; i+=2){
            if(n%i == 0){
                res.push_back(i);
                while(n%i == 0){
                    n /= i;
                }
            }
        }

        if(n>2) res.push_back(n);

        return res;

    }

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        map<int, vector<int>> mpp;
        for(int ele : nums){
            if(mpp[ele].empty()) mpp[ele] = f(ele);
        } 

        // for(auto it : mpp){
        //     int ele = it.first;
        //     cout<<it.first<<" : ";
        //     for(int ele : mpp[ele]) cout<<ele<<" ";
        //     cout<<endl;
        // }

        int maxi = 0;
        int l = 0, r = l;

        map<int, int> freq;

        while(r<n && l<n){
            while(r<n){
                // cout<<"r : "<<r<<" ";
                int ele = nums[r];
                for(int fac : mpp[ele]) freq[fac]++;
                if(freq.size() > k) break;
                // cout<<"len (r) : "<<r<<" len() "<<l<<" ";
                maxi = max(maxi, r-l+1);
                r++;
            }
            while(l<n){
                cout<<"l : "<<l<<" ";
                int ele = nums[l];
                for(int fac : mpp[ele]) {
                    if(freq[fac] > 0) {
                        // cout<<fac<<" ";
                        freq[fac]--;
                    }
                    if(freq[fac] <= 0) {
                        // cout<<"del : "<<fac<<" ";
                        freq.erase(fac);
                    }
                }
                l++;
                // cout<<"freq (size) : "<<freq.size()<<" ";
                // for(auto it : freq) cout<<it.first<<" ";
                if(freq.size() <= k) break;
            }
            r++;
            // cout<<endl;
        }

        return maxi;
    }
};