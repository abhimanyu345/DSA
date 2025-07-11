class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] && j!=i)
                    adj[i].push_back(j);
            }
        }

        vector<vector<int>>bfs;
        vector<int>vis(n, 0);
        queue<int>q;

        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                q.push(i);
                vis[i] = 1;
                vector<int>temp;
                while(!q.empty())
                {
                    int start = q.front();
                    q.pop();
                    temp.push_back(start);
                    for(int j=0; j<adj[start].size(); j++)
                    {
                        if(vis[adj[start][j]]==0)
                        {
                            q.push(adj[start][j]);
                            vis[adj[start][j]] = 1;
                        }   
                    }
                }
                bfs.push_back(temp);
            }
        }

        return bfs.size();
    }
};