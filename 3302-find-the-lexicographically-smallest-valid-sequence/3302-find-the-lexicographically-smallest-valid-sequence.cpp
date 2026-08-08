class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i]++;
                j--;
            }
        }

        vector<int> ans(m);

        int i = 0, k = 0;

        while (i < n && k < m) {
            if (word1[i] == word2[k]) {
                ans[k] = i;
                k++;
            }
            else if (dp[i + 1] >= m - k - 1) {
                ans[k] = i;
                k++;
                i++;
                break;
            }

            i++;
        }

        while (i < n && k < m) {
            if (word1[i] == word2[k]) {
                ans[k] = i;
                k++;
            }
            i++;
        }

        if (k < m)
            return {};

        return ans;
    }
};