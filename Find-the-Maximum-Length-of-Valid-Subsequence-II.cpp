class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(k, 0));
        vector<int>arr(k, -1);
        int maxlen = 1;

        arr[nums[0]%k] = 0;
        for(int i=0; i<k; i++)
            dp[0][i] = 1;
        
        for(int i=1; i<n; i++)
        {
            int rem = nums[i]%k;
            for(int j=0; j<k; j++)
            {
                if(j-rem>=0)
                {
                    if(arr[j-rem]!=-1)
                        dp[i][j] = 1+dp[arr[j-rem]][j];
                    else
                        dp[i][j] = 1;
                    maxlen = max(maxlen, dp[i][j]);
                }
                else
                {
                    if(arr[k-rem+j]!=-1)
                        dp[i][j] = 1+dp[arr[k-rem+j]][j];
                    else
                        dp[i][j] = 1;
                    maxlen = max(maxlen, dp[i][j]);
                }
            }
            arr[rem] = i;
        }

        return maxlen;
    }
};