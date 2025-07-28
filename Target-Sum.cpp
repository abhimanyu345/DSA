class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int k = (sum+target)/2;
        if(k<0)
        {
            return 0;
        }
        if((sum+target)%2)
        {
            return 0;
        }
        int n = nums.size();

        vector<vector<int>>dp(n, vector<int>(1000+1, 0));

        dp[0][nums[0]] = 1;
        dp[0][0] = 1;
        if(nums[0]==0)
        {
            dp[0][0] = 2;
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                int dontTake = dp[i-1][j]%LONG_MAX;
                int take = 0;
                if(nums[i]<=j)
                {
                    take = dp[i-1][j-nums[i]]%LONG_MAX;
                }
                dp[i][j] = ((long long)take+(long long)dontTake)%LONG_MAX;
            }
        }

        return dp[n-1][k];
    }
};