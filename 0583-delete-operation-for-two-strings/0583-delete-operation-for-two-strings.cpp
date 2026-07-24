class Solution {
public:

    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(a[i] == b[j]){
            return dp[i][j] = 1 + solve(i - 1, j - 1, a, b, dp);
        }

        return dp[i][j] = max(solve(i - 1,j,a,b,dp),
                solve(i,j - 1,a, b,dp));
    }

    int minDistance(string word1, string word2){
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int lcs = solve(n - 1,m - 1,word1,word2,dp);

        return n + m - 2 * lcs;
    }
};