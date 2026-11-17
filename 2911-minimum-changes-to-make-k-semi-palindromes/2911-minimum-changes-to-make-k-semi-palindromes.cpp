class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int l = 0; l < n; l++){
            for (int r = l + 1; r < n; r++){
                int len = r - l + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int groupLen = len / d;

                    for (int offset = 0; offset < d; offset++) {
                        for (int t = 0; t < groupLen / 2; t++) {
                            int a = l + offset + t * d;
                            int b = l + offset + (groupLen - 1 - t) * d;

                            if (s[a] != s[b]) {
                                changes++;
                            }
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int p = 2 * (j - 1); p <= i - 2; p++) {
                    if (dp[j - 1][p] == INF) continue;

                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][p] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
