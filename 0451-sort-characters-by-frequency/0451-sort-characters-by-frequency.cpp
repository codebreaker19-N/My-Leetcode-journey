class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char ch : s){
            freq[ch]++;
        }

        priority_queue< pair<int , char>> pq;

        for(auto it : freq){
            pq.push({it.second , it.first});
        }
        string ans = "";

        while(!pq.empty()) {

            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            while(count--) {
                ans += ch;
            }
        }

        return ans;
        
    }
};