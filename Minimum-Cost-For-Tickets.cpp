class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(366, 0);
        vector<int>vis(366, 0);
        for(int i=0; i<days.size(); i++)
            vis[days[i]] = 1;
            
        for(int i=1; i<=365; i++)
        {
            if(vis[i]==0)
                dp[i] = dp[i-1];
            else
            {
                int op1 = costs[0] + dp[i-1];
                int op2 = INT_MAX;
                if(i-7>=0)
                    op2 = costs[1] + dp[i-7];
                else
                    op2 = costs[1] + dp[0];
                int op3 = INT_MAX;
                if(i-30>=0)
                    op3 = costs[2] + dp[i-30];
                else
                    op3 = costs[2] + dp[0];
                dp[i] = min(op1, min(op2, op3));
            }
        }

        return dp[365];
    }
};