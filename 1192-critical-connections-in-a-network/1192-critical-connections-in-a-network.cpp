class Solution {
public:
    vector<vector<int>> graph;
    vector<int> disc, low, vis;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int node , int parent){
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        for(int nei : graph[node]){
            if(nei == parent)
             continue;
            if(!vis[nei]){
                dfs(nei , node);
                low[node] = min(low[node] , low[nei]);

                if(low[nei] > disc[node]){
                    ans.push_back({node , nei});

                }
            }
            else {
                    low[node] = min(low[node], disc[nei]);
                    }
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for(auto e : connections)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        disc.resize(n);
        low.resize(n);
        vis.assign(n,0);

        dfs(0,-1);

        return ans;
    }
};