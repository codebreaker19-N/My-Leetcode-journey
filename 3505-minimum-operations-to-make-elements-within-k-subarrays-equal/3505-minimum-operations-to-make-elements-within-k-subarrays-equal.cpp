
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k){
        int n = nums.size();
        multiset<int> left, right;
        long long sumL = 0, sumR = 0;
        auto add = [&](int v) {if (left.empty() || v <= *left.rbegin()){
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }

            if(left.size() > right.size()+1){
                int a = *left.rbegin();
                left.erase(left.find(a));
                sumL -= a;
                right.insert(a);
                sumR += a;
            }

            if(left.size() < right.size()){
                int a = *right.begin();
                right.erase(right.find(a));
                sumR -= a;
                left.insert(a);
                sumL += a;
            }
        };

        auto remove = [&](int v){
            if(left.find(v) != left.end()){
                left.erase(left.find(v));
                sumL -= v;
            } else{
                right.erase(right.find(v));
                sumR -= v;
            }

            if(left.size() > right.size()+1){
                int a = *left.rbegin();
                left.erase(left.find(a));
                sumL -= a;
                right.insert(a);
                sumR += a;
            }

            if(left.size() < right.size()){
                int a = *right.begin();
                right.erase(right.find(a));
                sumR -= a;
                left.insert(a);
                sumL += a;
            }
        };

        auto getCost = [&]()->long long{
            long long med = *left.rbegin();

            return med * left.size() - sumL+sumR- med * right.size();
        };

        vector<long long> cost;
        for (int i = 0;i<n;i++){
            add(nums[i]);

            if(i>=x){
                remove(nums[i - x]);
            }

            if(i>=x-1){
                cost.push_back(getCost());
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(k+1, vector<long long>(n+1, INF));

        for(int i=0; i<=n;i++) {
            dp[0][i] = 0;
        }

        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){

                dp[j][i] = dp[j][i-1];

                if (i>=x) {
                    dp[j][i] = min(
                        dp[j][i],dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
