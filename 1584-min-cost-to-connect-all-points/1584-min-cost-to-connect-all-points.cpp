class DSU {
    public: 
    vector<int> parent , rank;
    DSU (int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
         parent[i]=i;
    }
    int find(int x){
        if(parent[x] == x)
         return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)
         return;
        if(rank[x] < rank[y])
         swap(x,y);
        
        parent[y] = x;
        if(rank[x] == rank[y])
         rank[x]++;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int wt =
                abs(points[i][0]-points[j][0]) +
                abs(points[i][1]-points[j][1]);

                edges.push_back({wt, i, j});
            }
        }

        sort(edges.begin() , edges.end());
        DSU ds(n);

        int cost = 0;

        for(auto edge : edges){
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(ds.find(u) != ds.find(v)){
                ds.unite(u,v);
                cost += wt;
            }
        }
        return cost;
    }
};