class Solution {
public:

    class DSU
    {
    public:

        vector<int> parent;
        vector<int> rank;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=1;i<=n;i++)
                parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x)
                return x;

            return parent[x]=find(parent[x]);
        }

        bool Union(int u,int v){
            int pu=find(u);
            int pv=find(v);

            if(pu==pv)
                return false;

            if(rank[pu]<rank[pv])
                swap(pu,pv);

            parent[pv]=pu;

            if(rank[pu]==rank[pv])
                rank[pu]++;

            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n=edges.size();

        DSU dsu(n);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(!dsu.Union(u,v))
                return edge;
        }

        return {};
    }
};