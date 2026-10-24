class Solution {
public:
    int countDaysTogether(string a, string l, string b, string r) {
        string first = max(a,b);
        string last = min(l,r);

        if(first>last)
          return 0;
        
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto day = [&](string s){
            int m = stoi(s.substr(0,2));
            int d = stoi(s.substr(3,2));

            for(int i =0; i<m-1;i++){
                 d += days[i];
            }

            return d;
        };

        return day(last)-day(first)+1;
    }
};