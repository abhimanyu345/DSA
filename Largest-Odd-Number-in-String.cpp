class Solution {
public:
    string largestOddNumber(string num) {
        
        int i=num.size()-1;
        while(i>=0)
        {
            if((num[i]-'0')%2)
                break;
            i--;
        }

        if(i==-1)
            return "";
        string res = "";
        for(int j=0; j<=i; j++)
            res += num[j];
        return res;
    }
};