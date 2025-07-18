class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size()!=t.size())
            return false;
        unordered_map<char, char>mpp;

        for(int i=0; i<s.size(); i++)
        {
            if(mpp.find(s[i]) != mpp.end())
            {
                if(mpp[s[i]] != t[i])
                    return false;
            }
            mpp[s[i]] = t[i];
        }

        unordered_map<char, char>mpp1;
        for(int i=0; i<t.size(); i++)
        {
            if(mpp1.find(t[i]) != mpp1.end())
            {
                if(mpp1[t[i]] != s[i])
                    return false;
            }
            mpp1[t[i]] = s[i];
        }

        return true;
    }
};