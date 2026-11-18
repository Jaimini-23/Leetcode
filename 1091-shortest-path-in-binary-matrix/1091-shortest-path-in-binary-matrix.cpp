class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        dist[0][0] = 1;
        while(!q.empty()) {
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for(int delRow = -1; delRow <= 1; delRow++) {
                for(int delCol = -1; delCol <= 1; delCol++) {
                    int newr = row + delRow;
                    int newc = col + delCol;

                    if(newr >= 0 && newr < n && newc >= 0 && newc < m
                        && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {

                            dist[newr][newc] = dis + 1;
                            if(newr == n - 1 && newc == m - 1) return dis + 1;
                            q.push({dis + 1, {newr, newc}});
                        }
                }
            }
        }
        return -1;
    }
};