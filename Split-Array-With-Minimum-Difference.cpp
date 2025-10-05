class Solution {
public:
    long long splitArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n==2)
            return abs(nums[1]-nums[0]);
        vector<long long>dp(n, 0);
        dp[0] = nums[0];

        for(int i=1; i<n-1; i++)
        {
            if(nums[i]>nums[i-1])
                dp[i] = dp[i-1]+(long long)nums[i];
            else
                break;
        }
        long long ans = LLONG_MAX;
        long long right = 0;
        for(int i=n-1; i>0; i--)
        {
            if(i==n-1)
            {
                right += (long long)nums[n-1];
                if(i-1>=0 && dp[i-1]!=0)
                    ans = min(ans, abs(dp[i-1]-right));
            }
            else
            {
                if(nums[i]>nums[i+1])
                {
                    right += 1ll*nums[i];
                    if(i-1>=0 && dp[i-1]!=0)
                        ans = min(ans, abs(dp[i-1]-right));
                }
                else
                    break;
            }
        }

        cout<<right;
        if(ans==LLONG_MAX)
            return -1;
        return ans;
    }
};