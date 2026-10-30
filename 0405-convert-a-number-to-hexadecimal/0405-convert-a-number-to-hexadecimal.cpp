class Solution {
public:
    string toHex(int n) {
       if(n==0)
        return "0";
    
       string s = "0123456789abcdef";
       string ans = "";
       while(n){
        ans += s[n&15];
        n = (unsigned int) n >> 4;

       }
        
        reverse(ans.begin(), ans.end());

        return ans;

    }
};