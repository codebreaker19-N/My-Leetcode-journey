class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;

        for (int n : nums)
            x ^= n;

        if (x != 0)
            return nums.size();

        for (int n : nums){
            if (n != 0)
                return nums.size() - 1;
        }

        return 0;
    }
};