class Solution {
public:

    int solve(int index, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& dp){
        if(index < 0)
            return 0;

        if(dp[index][m][n] != -1)
            return dp[index][m][n];

        int notTake = solve(index - 1, m, n, strs, dp);

        int zeros = 0, ones = 0;

        for(char ch : strs[index]){
            if(ch == '0')
                zeros++;
            else
                ones++;
        }

        int take = 0;

        if(zeros <= m && ones <= n){
            take = 1 + solve(index - 1, m - zeros, n - ones, strs, dp);
        }

        return dp[index][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n){
        int sz = strs.size();

        vector<vector<vector<int>>> dp( sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve(sz - 1, m, n, strs , dp );
    }
};