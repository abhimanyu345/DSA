class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(), s.end());
        s += " ";
        string temp = "";
        vector<string>ans;
        string res = "";

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=32)
                temp += s[i];
            else if(temp!="")
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp = "";
            }
        }
        for(int i=0; i<ans.size(); i++)
        {
            res += ans[i];
            res += " ";
        }
        
        res.pop_back();
        return res;
    }
};