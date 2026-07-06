class Solution {
public:
    
    vector<vector<string>> ans;

    vector<int> column;
    vector<int> diag1;
    vector<int> diag2;

    void solve(int row , vector<string>& board, int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n;col++){
            int d1 = row-col+n-1;
            int d2 = row+col;

            if(column[col] || diag1[d1] || diag2[d2])
                continue;
            board[row][col] = 'Q';
            column[col] = diag1[d1] = diag2[d2] = 1;

            solve(row + 1, board, n);

            board[row][col] = '.';
            column[col] = diag1[d1] = diag2[d2] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        column.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        solve(0, board, n);

        return ans;
        
    }
};