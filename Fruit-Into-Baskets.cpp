class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int r = 0;
        int l = 0;
        int maxlen = 0;
        unordered_map<int, int>mpp;

        while(r<fruits.size())
        {
            mpp[fruits[r]]++;
            if(mpp.size()<=2)
            {
                maxlen = max(maxlen, r-l+1);
                r++;
            }
            else
            {
                while(mpp.size()>2)
                {
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0)
                        mpp.erase(fruits[l]);
                    l++;
                }
                maxlen = max(maxlen, r-l+1);
                r++;
            }
        }

        return maxlen;
    }
};