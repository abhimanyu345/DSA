class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        string anchor = strs[0];

        for(int i=0; i<anchor.size(); i++)
        {
            int flag = 0;
            for(int j=0; j<strs.size(); j++)
            {
                if(strs[j].size()>=i && strs[j][i]==anchor[i])
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
                ans += anchor[i];
            else
                return ans;
        }

        return ans;
    }
};