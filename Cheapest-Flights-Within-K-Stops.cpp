class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<int>dist(n, INT_MAX);
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0; i<flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        pq.push({0, {0, src}});
        dist[src] = 0;

        while(!pq.empty())
        {
            auto [stops, it] = pq.top();
            int d = it.first;
            int node = it.second;
            pq.pop();
            for(int i=0; i<adj[node].size(); i++)
            {
                if(1+stops<=k+1)
                {
                    if(d+adj[node][i].second < dist[adj[node][i].first])
                    {
                        dist[adj[node][i].first] = d+adj[node][i].second;
                        pq.push({stops+1, {dist[adj[node][i].first], adj[node][i].first}});
                    }
                }
            }
        }

        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};