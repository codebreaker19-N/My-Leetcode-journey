class DSU{
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x)
         return x;
        
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (rank[x] < rank[y])
            swap(x, y);

        parent[y] = x;

        if (rank[x] == rank[y])
            rank[x]++;

        return true;
    }
};
class Solution {
public:
    int kruskal(int n,
                vector<vector<int>>& edges,
                int skipEdge,
                int forceEdge) {

        DSU ds(n);
        int weight = 0;
        int edgesUsed = 0;
        if(forceEdge != -1)
    {
        int u = edges[forceEdge][0];
        int v = edges[forceEdge][1];
        int w = edges[forceEdge][2];

        if(ds.unite(u,v))
        {
            weight += w;
            edgesUsed++;
        }
    }

    for(int i=0;i<edges.size();i++)
    {
        if(i==skipEdge) continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(ds.unite(u,v))
        {
            weight += w;
            edgesUsed++;
        }
    }
        

        if (edgesUsed != n - 1)
            return INT_MAX;

        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges( int n, vector<vector<int>>& edges){
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
         [](vector<int>& a, vector<int>& b){
         return a[2] < b[2];
        });

        int originalWeight = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < edges.size(); i++){
            if (kruskal(n, edges, i, -1) > originalWeight)
            {
                critical.push_back(edges[i][3]);
            }
            else if (kruskal(n, edges, -1, i) == originalWeight)
            {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical , pseudo};
    }
        
    
};