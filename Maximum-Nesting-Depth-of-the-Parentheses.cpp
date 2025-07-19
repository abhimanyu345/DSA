class Solution {
public:
    int maxDepth(string s) {
        
        int ans = 0;
        int active = 0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                active++;
                ans = max(ans, active);
            }
            else if(s[i]==')')
            {
                active--;
            }
        }

        return ans;
    }
};