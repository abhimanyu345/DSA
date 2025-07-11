class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        const int MOD = 1e9 + 7;

        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();

            if (d > dist[node]) continue;

            for (auto &[next, wt] : adj[node]) {
                ll newDist = d + wt;
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.push({newDist, next});
                    ways[next] = ways[node];
                } else if (newDist == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
