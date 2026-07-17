class Solution {
public:
    int dfs(int row, int col , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row >= m || col >= n)
            return 0;

        if(grid[row][col] == 0)
            return 0;

        grid[row][col] = 0;
        int area = 1;

        area += dfs(row+1, col, grid);
        area += dfs(row-1, col, grid);
        area += dfs(row, col+1, grid);
        area += dfs(row, col-1, grid);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans = max(ans, dfs(i,j,grid));
                }
            }
        }

        return ans;
        
    }
};