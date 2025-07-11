class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        queue<pair<int, int>>q;
        vector<pair<int, int>>dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int cnt = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i, j});
                    }
                }
            }
        }

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if(vis[x][y]==0)
            {
                vis[x][y] = 1;
                for(auto [dx, dy]:dir)
                {
                    int nx = x+dx;
                    int ny = y+dy;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                        q.push({nx, ny});
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] && vis[i][j]==0)
                    cnt++;
            }
        }

        return cnt;
    }
};