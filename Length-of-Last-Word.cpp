class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i = s.size()-1;
        while(i>=0)
        {
            if(s[i]==32)
                i--;
            else
                break;
        }

        cout<<i;
        int len = 0;
        while(i>=0)
        {
            if(s[i]!=32)
              len++;
            else
                break;  
            i--;
        }

        return len;
    }
};