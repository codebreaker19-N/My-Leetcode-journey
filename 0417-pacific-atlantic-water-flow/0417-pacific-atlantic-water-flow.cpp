class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void bfs(queue<pair<int,int>> &q,
             vector<vector<int>> &vis,
             vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        while(!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 &&
                   nr < m &&
                   nc >= 0 &&
                   nc < n &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[row][col])
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        for(int i = 0; i < m; i++){
            pacQ.push({i, 0});
            pac[i][0] = 1;
        }

        for(int j = 1; j < n; j++){
            pacQ.push({0, j});
            pac[0][j] = 1;
        }

        bfs(pacQ, pac , heights);


        for(int i = 0; i < m; i++){
            atlQ.push({i, n-1});
            atl[i][n-1] = 1;
        }

        
        for(int j = 0; j < n-1; j++){
            atlQ.push({m-1, j});
            atl[m-1][j] = 1;
        }

        bfs(atlQ, atl, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};