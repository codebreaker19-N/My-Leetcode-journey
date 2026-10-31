
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int n = grid[0].size();
        vector<int> down(n, 0);
        down[0] = 1;
        for (auto &row : grid) {
            int right = 0;
            for (int j = 0; j < n; j++) {
                if (row[j] == 1) {
                    int temp = right;
                    right = down[j];
                    down[j] = temp;
                } 
                else {
                    right = down[j] = (right + down[j]) % MOD;
                }
            }
        }

        return down[n - 1];
    }
};
