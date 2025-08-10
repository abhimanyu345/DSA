class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        vector<vector<int>>arr(k);

        for(int i=x+k-1; i>=x; i--)
        {
            for(int j=y; j<y+k; j++)
            {
                arr[x+k-1-i].push_back(grid[i][j]);
            }
        }
        for(int i=x; i<x+k; i++)
        {
            for(int j=y; j<y+k; j++)
            {
                grid[i][j] = arr[i-x][j-y];
            }
        }

        return grid;
    }
};