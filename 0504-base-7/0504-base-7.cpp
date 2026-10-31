class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        bool negative = num < 0;
        long long n = abs((long long)num);

        string ans = "";
        while (n > 0) {
            int rem = n % 7;
            ans += to_string(rem);
            n /= 7;
        }
        reverse(ans.begin(), ans.end());
        if (negative)
            ans = "-" + ans;

        return ans;
    }
};