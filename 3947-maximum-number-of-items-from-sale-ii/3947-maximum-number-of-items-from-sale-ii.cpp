class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        vector<pair<int, int>> bonus;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (gain[factor] > 0 && 1LL * price < 2LL * minPrice) {
                bonus.push_back({price, gain[factor]});
            }
        }

        sort(bonus.begin(), bonus.end());

        long long ans = 0;
        long long remaining = budget;

        for (auto [price, count] : bonus) {
            long long buy = min(1LL * count, remaining / price);

            ans += 2 * buy;
            remaining -= buy * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};
