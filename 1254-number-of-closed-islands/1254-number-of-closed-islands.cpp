class Solution {
public:



    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visi){

        int m = grid.size();
        int n = grid[0].size();

        int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        visi[i][j] = 1;
        q.push({i, j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + x[i];
                int nc = c + y[i];
            if (nr>=0 && nr<m && nc>=0 && nc<n){
                if(grid[nr][nc] == 0 && !visi[nr][nc]){
                    q.push({nr, nc});
                    visi[nr][nc] = 1;
                }
            }
            }
        }
        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visi(m, vector<int>(n, 0));
        int ctn = 0;

        for(int i=0; i<m; i++) {
                if(grid[i][0] != 1){
                    if(!visi[i][0]) {
                        
                        bfs(i, 0, grid, visi);
                    }
                }
        }
        for(int i=0; i<n; i++) {
                if(grid[0][i] != 1){
                    if(!visi[0][i]) {
                       
                        bfs(0, i, grid, visi);
                    }
                }
        }
    for(int i=0; i<n; i++) {
                if(grid[m-1][i] != 1){
                    if(!visi[m-1][i]) {
                        
                        bfs(m-1, i, grid, visi);
                    }
                }
        }
        for(int i=0; i<m; i++) {
                if(grid[i][n-1] != 1){
                    if(!visi[i][n-1]) {
                        
                        bfs(i, n-1, grid, visi);
                    }
                }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 1){
                    if(!visi[i][j]) {
                        ctn++;
                        bfs(i, j, grid, visi);
                    }
                }
            }
        }
        return ctn;
    }
};