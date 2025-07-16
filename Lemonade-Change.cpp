class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five = 0;
        int ten = 0;
        int n = bills.size();
        
        for(int i=0; i<n; i++)
        {
            if(bills[i]-5 != 0)
            {
                int rem = bills[i]-5;
                if(rem==5)
                {
                    if(five==0)
                        return false;
                    else
                    {
                        five--;
                        ten++;
                    }
                }
                else
                {
                    if(ten && five)
                    {
                        ten--;
                        five--;
                    }
                    else if(five>=3)
                    {
                        five -= 3;
                    }
                    else
                        return false;
                }
            }
            else
            {
                five++;
            }
        }
        
        return true;
    }
};