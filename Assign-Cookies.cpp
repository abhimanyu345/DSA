class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0;
        int j = 0;
        if(s.size()==0)
            return 0;
        
        int count = 0;
        while(i<g.size() && j<s.size())
        {
            if(g[i]<=s[j])
            {
                count++;
                i++;
                j++;
            }
            else if(s[j]<g[i])
            {
                j++;
            }
        }

        return count;

    }
};