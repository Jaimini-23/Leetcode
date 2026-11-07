class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        vector<vector<int>> vis = grid;
        queue<pair<pair<int,int>,int>> q;
        int cntFresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1) cntFresh++;
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time,t);
            for(int delrow = -1; delrow <= 1; delrow++) {
                for(int delcol = -1; delcol <= 1; delcol++) {
                    if(abs(delrow) + abs(delcol) != 1) continue;
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && vis[nrow][ncol] == 1) {
                            vis[nrow][ncol] = 2;
                            q.push({{nrow,ncol},t + 1});
                            cnt++;
                        }
                }
            }
        }
        if(cntFresh != cnt) return -1;
        return time;
    }
};