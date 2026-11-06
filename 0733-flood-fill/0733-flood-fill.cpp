class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= m; delcol++) {
                if(abs(delrow) + abs(delcol) != 1) continue;
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                        dfs(nrow, ncol, ans, image, newColor, iniColor);
                    }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, color, iniColor);
        return ans;
    }
};