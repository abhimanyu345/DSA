class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2, 0));
        int odd = -1;
        int even = -1;
        dp[0][0] = 1;
        dp[0][1] = 1;
        if(nums[0]%2)
            odd = 0;
        else
            even = 0;
        int ans = 0;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i]%2==1)
            {
                if(even!=-1)
                    dp[i][1] = dp[even][1]+1;
                else
                    dp[i][1] = 1;
                
                if(odd!=-1)
                    dp[i][0] = dp[odd][0]+1;
                else
                    dp[i][0] = 1;
                odd = i;
                ans = max(ans, max(dp[i][0], dp[i][1]));
            }
            else
            {
                if(odd!=-1)
                    dp[i][1] = dp[odd][1]+1;
                else
                    dp[i][1] = 1;
                
                if(even!=-1)
                    dp[i][0] = dp[even][0]+1;
                else
                    dp[i][0] = 1;
                even = i;
                ans = max(ans, max(dp[i][0], dp[i][1]));
            }
        }

        return ans;
    }
};