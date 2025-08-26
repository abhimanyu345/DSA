class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        double maxd = 0;
        int maxa = 0;

        for(int i=0; i<dimensions.size(); i++)
        {
            double d = sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            if(d>maxd)
            {
                maxd = d;
                maxa = dimensions[i][0]*dimensions[i][1];
            }
            else if(d==maxd)
            {
                maxa = max(maxa, dimensions[i][1]*dimensions[i][0]);
            }
        }

        return maxa;
    }
};