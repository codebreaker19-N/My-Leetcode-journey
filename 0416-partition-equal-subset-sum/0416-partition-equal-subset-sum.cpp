class Solution {
public:
    bool solve(int idx , int target , vector<int>& nums , vector<vector<int>>& dp){
        
        if(target == 0)
         return true;
        
        if(idx == 0)
         return nums[0] == target;

        if(dp[idx][target] != -1)
         return dp[idx][target];

        bool notTake = solve(idx-1 , target , nums , dp);
        bool take = false;

        if(nums[idx] <= target){
            take = solve(idx-1 , target-nums[idx] , nums , dp);
        }

        return dp[idx][target] = take || notTake;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums)
         sum += x;
        
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target + 1,-1));

        return solve(n-1 , target , nums , dp);
        
    }
};