class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time ;
        for ( string s : timePoints){
            int h = stoi(s.substr(0,2));
            int m = stoi(s.substr(3,2));
            time.push_back(h*60+m);
        }
        //23:59 
        //01234
        sort(time.begin() , time.end());
        int ans = 1440 ; 
        for ( int i = 1 ; i < time.size() ; i++){
            ans = min( ans , time[i] - time[i-1]);
        }
        ans = min(ans , 1440 - time.back() + time[0]);
        return ans ;
    }   
};