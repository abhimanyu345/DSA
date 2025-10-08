class Solution {
public:
    string convert(string s, int numRows) {
        
        int flag = 0;
        int i = 0;
        int j = 0;
        vector<vector<string>>arr(numRows, vector<string>(1000, ""));
        int cur = 0;
        
        while(cur<s.size())
        {
            if(flag==0 || i==0)
            {
                flag = 0;
                arr[i][j] = s[cur];
                cur++;
                i++;
                if(i==numRows)
                {
                    flag=1;
                    j++;
                    if(i-2>=0)
                        i-=2;
                    else
                        break;
                }
            }
            else
            {
                arr[i][j] = s[cur];
                cur++;
                i--;
                j++;
                if(i==0)
                {
                    flag = 0;
                }
            }
        }
        
        string ans = "";
        for(int a=0; a<numRows; a++)
        {
            for(auto it:arr[a])
                ans+=it;
        }
        while(cur<s.size())
        {
            ans += s[cur];
            cur++;
        }
        return ans;

    }
};