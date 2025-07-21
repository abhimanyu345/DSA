class Solution {
public:
    string makeFancyString(string s) {
        
        if(s.size()<=2)
            return s;
        string ans = "";
        int x = s[0];
        int y = s[1];
        ans += x;
        ans += y;

        for(int i=2; i<s.size(); i++)
        {
            if(s[i]==x && s[i]==y)
                continue;
            else
            {
                ans += s[i];
                x = s[i-1];
                y = s[i];
            }
        }
        
        return ans;
    }
};