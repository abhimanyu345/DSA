class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m, vector<int>(n, -1));
        vector<pair<int, int>>dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<pair<int, int>, int>>q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }        
            }
        }

        while(!q.empty())
        {
            auto [cor, dis] = q.front();
            int x = cor.first;
            int y = cor.second;
            q.pop();
            for(auto [dx, dy]: dir)
            {
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]==1)
                {
                    mat[nx][ny] = 0;
                    q.push({{nx, ny}, dis+1});
                    ans[nx][ny] = dis+1;
                }
            }
        }

        return ans;
    }
};