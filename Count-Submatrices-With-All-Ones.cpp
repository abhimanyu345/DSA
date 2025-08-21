class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> height(m, vector<int>(n, 0));
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) continue;

            height[i][j] = (i > 0 ? height[i-1][j] : 0) + 1;

            int minH = height[i][j];
            for (int k = j; k >= 0 && minH > 0; k--) {
                minH = min(minH, height[i][k]);
                cnt += minH;
            }
        }
    }
    return cnt;
}

};