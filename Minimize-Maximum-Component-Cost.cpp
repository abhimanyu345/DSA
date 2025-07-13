class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;
        parent[yr] = xr;
        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<int> usedEdges;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (unite(u, v)) {
                usedEdges.push_back(w);
            }
        }

        // Initially 1 component (MST), remove k - 1 largest edges
        int components = 1;
        while (components < k && !usedEdges.empty()) {
            usedEdges.pop_back(); // remove largest edge
            components++;
        }

        return usedEdges.empty() ? 0 : *max_element(usedEdges.begin(), usedEdges.end());
    }
};
