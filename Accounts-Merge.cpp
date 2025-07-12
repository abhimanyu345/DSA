class DisjointSet {
    vector<int>parent, rank;
    public:
        DisjointSet (int n)
        {
            parent.resize(n+1, 0);
            rank.resize(n+1, 0);
            for(int i=0; i<=n; i++)
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
            int prev_x = findParent(x);
            int prev_y = findParent(y);
            if(rank[prev_x] > rank[prev_y])
            {
                parent[prev_y] = prev_x;
            }
            else if(rank[prev_y] > rank[prev_x])
            {
                parent[prev_x] = prev_y;
            }
            else
            {
                parent[prev_x] = prev_y;
                rank[prev_y]++;
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string, int>mpp;
        int n = accounts.size();
        DisjointSet ds(n);

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mpp.find(mail)==mpp.end())
                {
                    mpp[mail] = i;
                }
                else
                {
                    ds.Union(i, mpp[mail]);
                }
            }
        }

        vector<vector<string>>mergedMails(n);
        for(auto it:mpp)
        {
            int node = ds.findParent(it.second);
            mergedMails[node].push_back(it.first);
        }

        vector<vector<string>>ans;
        for(int i = 0; i < mergedMails.size(); i++) {
    if(mergedMails[i].size() == 0) continue;  // fixed check
    sort(mergedMails[i].begin(), mergedMails[i].end());
    vector<string> temp;
    temp.push_back(accounts[ds.findParent(i)][0]);  // use representative's name
    for (auto &email : mergedMails[i]) {
        temp.push_back(email);
    }
    ans.push_back(temp);
}


        return ans;
    }
};