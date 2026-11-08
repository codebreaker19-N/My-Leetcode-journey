class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({times[i][0], times[i][1], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> chair(n, -1);
        for(int i=0;i<n;i++){
            int start = arr[i][0];
            int end = arr[i][1];
            int index = arr[i][2];
            int c = 0;
            while(c<n && chair[c] > start){
                c++;
            }
            if(index == targetFriend){
                return c;
            }
            chair[c] = end;
        }
        return -1;
    }
};