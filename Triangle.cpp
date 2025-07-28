class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m, vector<int>(n, 1e9));

        dp[0][0] = triangle[0][0];
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<triangle[i].size(); j++)
            {
                if(j==0)
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                else if (j == triangle[i].size() - 1)
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            mini = min(mini, dp[m-1][i]);
        }
        
        return mini;
    }
};