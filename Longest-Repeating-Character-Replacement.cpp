class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int r = 0;
        int l = 0;
        int maxlen = 0;
        int maxf = 0;
        unordered_map<int, int>mpp;
        
        while(r<s.size())
        {
            mpp[s[r]-'A']++;
            maxf = max(maxf, mpp[s[r]-'A']);
            while((r-l+1)-maxf > k)
            {
                maxf = 0;
                mpp[s[l]-'A']--;
                for(int i=0; i<=25; i++)
                {
                    maxf = max(maxf, mpp[i]);
                }
                l++;
            }
            if((r-l+1)-maxf<=k)
                maxlen = max(maxlen, r-l+1);
            r++;
        }

        return maxlen;
    }
};