class DisjointSet {
vector<int>parent, rank;
public:
    DisjointSet (int n){
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++)
            parent[i] = i;
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
        if(rank[par_x] > rank[par_y])
        {
            parent[par_y] = par_x;
        }
        else if(rank[par_y] > rank[par_x])
        {
            parent[par_x] = par_y;
        }
        else
        {
            parent[par_x] = par_y;
            rank[par_y]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.Union(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findParent(it.first) == it.first) {
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};