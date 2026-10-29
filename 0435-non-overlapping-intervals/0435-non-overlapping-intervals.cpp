class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int end = intervals[0][1];  // first interval's ending point 
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end){    // current interval ka starting point  should be less than end 
                count++;
                end = min(end, intervals[i][1]);  // jab doo overlap krte h then we prefer jo phele end krta h that's way min 
            }
            else{
                end = intervals[i][1];  // not overlap then keep 
            }
        }

        return count;
    }
};