class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m, vector<int>(n, 0));

        for(int i=0; i<n; i++)
        {
            if(text1[0]==text2[i])
            {
                dp[0][i] = 1;
            }
            else if(i>0)
            {
                dp[0][i] = dp[0][i-1];
            }
        }

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(text1[i]==text2[j])
                {
                    if(j>0)
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    int move1 = dp[i-1][j];
                    int move2 = 0;
                    if(j>0)
                    {
                        move2 = dp[i][j-1];
                    }
                    dp[i][j] = max(move1, move2);
                }
            }
        }

        return dp[m-1][n-1];
    }
};