class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        int cnt = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==1)
                    dp[i][j] = 1;
            }
        }

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==1 && j>0)
                {
                    int min_sq = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                    dp[i][j] += min_sq;
                    cnt += dp[i][j];
                }
                else if(matrix[i][j]==1)
                    cnt += dp[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            cnt += dp[0][i];
        }

        return cnt;
    }
};