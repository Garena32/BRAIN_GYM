class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowcoll(m), colcoll(n);

        for(int i=0; i<m; i++){
            int ctn = 0;
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) ctn++;
            }
            rowcoll[i] = ctn;
    
        }
    
for(int i=0; i<n; i++){
            int ctn = 0;
            for(int j=0; j<m; j++){
                if(grid[j][i] == 1) ctn++;
            }
            colcoll[i] = ctn;
        }    

        for(int ele : rowcoll) cout << ele << " ";
        cout << endl;
        for(int ele : colcoll) cout << ele << " ";

        int a = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && rowcoll[i]+colcoll[j] > 2) {
                    a++;
                }
            }
        }

        return a;

    }

};