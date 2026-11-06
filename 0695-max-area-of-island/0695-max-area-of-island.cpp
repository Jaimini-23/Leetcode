class Solution {
public:
    void bfSearch(int row, int col,int &cnt, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        cnt++;
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delRow = -1; delRow <= 1; delRow++) {
                for(int delCol = -1; delCol <= 1; delCol++) {
                    if(abs(delRow) + abs(delCol) != 1) continue;
                    int nrow = row + delRow;
                    int ncol = col + delCol;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                        && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                            cnt++;
                            vis[nrow][ncol] = 1;
                            q.push({nrow,ncol});
                        }
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                int cnt = 0;
                if(!vis[row][col] && grid[row][col] == 1) {
                    bfSearch(row, col, cnt, vis, grid);
                }
                maxi = max(cnt, maxi);
            }
        }
        return maxi;
    }
};