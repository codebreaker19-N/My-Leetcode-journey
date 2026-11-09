class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentaltitude = 0;
        int maxaltitude = 0;

        for(int g:gain){
            currentaltitude += g ;
            maxaltitude = max(currentaltitude , maxaltitude);
        }
        return maxaltitude;
        
    }
};