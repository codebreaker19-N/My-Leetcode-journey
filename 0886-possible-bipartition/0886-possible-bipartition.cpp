class Solution {
public:
    bool dfs(int node , int currColor , vector<vector<int>>& graph , vector<int>& color){
        color[node] = currColor;
        for(int nei : graph[node]){
            if(color[nei] == -1){
                if(!dfs(nei , 1- currColor , graph , color))
                 return false;
            }

            else if(color[nei] == currColor){
                return false;
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);

        for(auto edge : dislikes){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);


        }

        vector<int> color(n+1,-1);
        for(int i =0 ; i< n ; i++){
            if(color[i] == -1){
                if(!dfs(i,0,graph,color))
                 return false;
            }
        } 

        return true;       
    }
};