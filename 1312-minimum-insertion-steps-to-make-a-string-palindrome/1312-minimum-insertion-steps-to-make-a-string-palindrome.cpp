class Solution {
public:
    int minInsertions(string s){
        int n = s.size();

        vector<int> dp(n, 0);

        for (int i = n-1;i>=0;i--){
            int prev = 0;
            dp[i] = 1;

            for (int j =i+1;j<n; j++){
                int temp = dp[j];

                if (s[i]==s[j]){
                    dp[j] = prev+2;
                }
                else {
                    dp[j] = max(dp[j], dp[j-1]);
                }

                prev= temp;
            }
        }

        return n-dp[n-1];
    }
};