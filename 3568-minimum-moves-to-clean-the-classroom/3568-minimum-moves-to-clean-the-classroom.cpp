class Solution {
public:
    // Use extra state when same state(r, c) can be reached with diff situation
    // here same (r, c) can be reached with diff energy and L

    struct State {
        int r;
        int c;
        int ce;
        int cm;
        int steps;
    };


    int minMoves(vector<string>& grid, int energy) {

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        int m = grid.size();
        int n = grid[0].size();

        int sr, sc;
        int nl = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
                if(grid[i][j] == 'L') {
                    id[i][j] = nl;
                    nl++;
                }
            }
        }

        int fullMask = (1<<nl)-1;

        vector<vector<vector<vector<int>>>> visi(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy+1, vector<int>(1<<nl))));

        queue<State> pq;
        pq.push({sr, sc, energy, 0, 0});
       

        while(!pq.empty()){


            State it = pq.front();
            pq.pop();


            int r = it.r;
            int c = it.c;
            int e = it.ce;
            int cm = it.cm;
            int steps = it.steps;

            if(cm == fullMask) return steps;

            for(int i=0; i<4; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){

                    if(e == 0) continue;

                    int nm = cm;

                    int ne = e - 1;

                    if(grid[nr][nc] == 'L') nm |= (1 << id[nr][nc]);

                    if(grid[nr][nc] == 'R') ne = energy;
                  
                    if(ne>=0 && !visi[nr][nc][ne][nm] && grid[nr][nc] != 'X'){
                        visi[nr][nc][ne][nm] = 1;
                        pq.push({nr, nc, ne, nm, steps+1});

                    }
                }
            }
        }
        return -1;
    }
};