class Solution{
public:

    int solve(vector<int>& nums){
        int n=nums.size();
        if(n==1)
            return nums[0];

        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int take=nums[i]+prev2;
            int notTake=prev1;

            int curr=max(take,notTake);

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums){
        int n=nums.size();

        if(n==1)
            return nums[0];

        vector<int> first(nums.begin(),nums.end()-1);

        vector<int> second(nums.begin()+1,nums.end());

        return max(
            solve(first),
            solve(second)
        );
    }
};