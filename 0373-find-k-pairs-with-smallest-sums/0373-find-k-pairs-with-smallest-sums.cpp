class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        if(nums1.empty() || nums2.empty())
            return ans;
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        int n = nums1.size();

        for(int i = 0; i < min(n, k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- && !pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int sum = curr[0];
            int i = curr[1];
            int j = curr[2];

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size()) {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
        
    }
};