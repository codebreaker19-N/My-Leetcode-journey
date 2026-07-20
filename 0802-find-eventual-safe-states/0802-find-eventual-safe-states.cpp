class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> outDegree(n, 0);
        for(int u = 0; u < n; u++){
            outDegree[u] = graph[u].size();
             for(int v : graph[u]){
                revGraph[v].push_back(u);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(outDegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int parent : revGraph[node]){
                outDegree[parent]--;

                if(outDegree[parent] == 0)
                    q.push(parent);
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
        
    }
};