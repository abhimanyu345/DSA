class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int mini = INT_MAX;
        int ans = -1;
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        for(int src=0; src<n; src++)
        {
            vector<int>dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            dist[src] = 0;
            pq.push({0, src});
            
            while(!pq.empty())
            {
                auto [d, node] = pq.top();
                pq.pop();
                for(int i=0; i<adj[node].size(); i++)
                {
                    if(dist[adj[node][i].first]>d+adj[node][i].second && d+adj[node][i].second<=distanceThreshold)
                    {
                        pq.push({d+adj[node][i].second, adj[node][i].first});
                        dist[adj[node][i].first] = d+adj[node][i].second;
                    }
                }
            }

            int cnt = 0;
for (int i = 0; i < n; i++) {
    if (i != src && dist[i] <= distanceThreshold)
        cnt++;
}

            if (cnt < mini || (cnt == mini && src > ans)) {
    ans = src;
    mini = cnt;
}

        }

        return ans;
    }
};