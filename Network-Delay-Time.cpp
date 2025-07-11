class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>dist(n+1, INT_MAX);
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0; i<times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            for(int i=0; i<adj[node].size(); i++)
            {
                if(dist[adj[node][i].first]>d+adj[node][i].second)
                {
                    dist[adj[node][i].first] = d+adj[node][i].second;
                    pq.push({dist[adj[node][i].first], adj[node][i].first});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};