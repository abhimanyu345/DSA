class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>>q;
        vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        int ori = image[sr][sc];
        if(ori==color)
            return image;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy]: dir)
            {
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==ori)
                {
                    q.push({nx, ny});
                    image[nx][ny] = color;
                }
            }
            
        }

        return image;
    }
};