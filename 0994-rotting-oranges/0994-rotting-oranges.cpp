class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        queue<pair<int,int>> q;

        int fresh=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});

                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        int minutes=0;

        while(!q.empty() && fresh>0)
        {
            int sz=q.size();

            while(sz--)
            {
                auto [row,col]=q.front();
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int nr=row+dr[k];
                    int nc=col+dc[k];

                    if(nr>=0 && nr<m &&
                       nc>=0 && nc<n &&
                       grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }

            minutes++;
        }

        if(fresh == 0)
         return minutes;

        return -1;

        
    }
};