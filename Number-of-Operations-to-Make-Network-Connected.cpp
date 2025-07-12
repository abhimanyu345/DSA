class DisjointSet {
    vector<int> rank, parent;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            for(int i=0; i<n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int x)
        {
            if(parent[x]==x)
                return x;
            else
                return parent[x] = findParent(parent[x]);
        }

        void Union(int x, int y)
        {
            int par_x = findParent(x);
            int par_y = findParent(y);
            if(rank[par_x] < rank[par_y])
            {
                parent[par_x] = par_y;
            }
            else if(rank[par_y] < rank[par_x])
            {
                parent[par_y] = par_x;
            }
            else
            {
                parent[par_y] = par_x;
                rank[par_x]++;
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int cnt = 0;
        DisjointSet ds(n);
        for(int i=0; i<connections.size(); i++)
        {
            int x = connections[i][0];
            int y = connections[i][1];
            if(ds.findParent(x)==ds.findParent(y))
                continue;
            cnt++;
            ds.Union(x, y);
        }

        vector<vector<int>>bfs;
        vector<int>vis(n, 0);
        queue<int>q;
        
        for(int i=0; i<n; i++)
        {
            if(vis[i]!=1)
            {
                vector<int>temp;
                q.push(i);
                vis[i] = 1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    temp.push_back(node);
                    for(int i=0; i<adj[node].size(); i++)
                    {
                        if(vis[adj[node][i]]==0)
                        {
                            q.push(adj[node][i]);
                            vis[adj[node][i]] = 1;
                        }
                    }
                }
                bfs.push_back(temp);
            }
        }

        if(bfs.size()==1)
            return 0;
        int rem = connections.size()-cnt;
        if(bfs.size()-1>rem)
            return -1;
        return bfs.size()-1;
    }
};