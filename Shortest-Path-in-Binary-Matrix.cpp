class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>>q;
        q.push({1, {0, 0}});
        vector<pair<int, int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1},
        {-1, 1}, {1, -1}};
        if(grid[0][0])
            return -1;
        dist[0][0] = 1;
        
        while(!q.empty())
        {
            auto it = q.front();
            int x = it.second.first;
            int y = it.second.second;
            int d = it.first;
            q.pop();

            for(auto [dx, dy]: dir)
            {
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0)
                {
                    if(dist[nx][ny]>1+d)
                    {
                        dist[nx][ny] = 1+d;
                        q.push({1+d, {nx, ny}});
                    }
                }
            }
        }

        if(dist[n-1][n-1]==INT_MAX)
            return -1;
        return dist[n-1][n-1];
    }
};