class Solution {
public:
    int n;
    long long mod = 1e9 + 7;

    long long power(long long a, int b) {
        long long result = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1)
                result = (result * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return result;
    }

    bool check(vector<int>& v, int sz, long long base) {
        unordered_map<long long, int> mp;
        long long p = power(base, sz - 1);
        long long roll = 0;
        int l = 0;
        int i = 0;

        while (i < n) {
            roll = (roll * (base % mod) + v[i]) % mod;

            if (i - l + 1 < sz)
                i++;
            else {
                mp[roll]++;
                roll = (roll - (p * v[l]) % mod + mod) % mod;
                l++, i++;
            }
        }

        for (auto p : mp) {
            if (p.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& v) {
        n = v.size();
        if (n == 0) return 0;

        int ans = 0;
        int l = 1, r = n;
        long long base = (long long) *max_element(v.begin(), v.end()) + 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(v, mid, base))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        return ans;
    }
};