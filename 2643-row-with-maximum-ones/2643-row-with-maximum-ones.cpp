class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int cntMax = 0;
        int index = 0;

        for(int i = 0; i < m; i++) {
            int cntOnes = 0;

            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    cntOnes++;
                }
            }

            if(cntOnes > cntMax) {
                cntMax = cntOnes;
                index = i;
            }
        }

        return {index, cntMax};
    }
};