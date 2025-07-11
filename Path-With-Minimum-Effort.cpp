class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>effort(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<pair<int, int>>dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty())
        {
            auto it = pq.top();
            int x = it.second.first;
            int y = it.second.second;
            int h = it.first;
            pq.pop();
            for(auto [dx, dy]:dir)
            {
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    int currentEffort = max(h, abs(heights[nx][ny] - heights[x][y]));
                    if (currentEffort < effort[nx][ny]) {
                        effort[nx][ny] = currentEffort;
                        pq.push({currentEffort, {nx, ny}});
                    }
                }
            }
        }

        return effort[m-1][n-1];
    }
};