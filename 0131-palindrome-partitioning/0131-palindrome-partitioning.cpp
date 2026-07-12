class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    
    bool isPalindrome(string &s, int left , int right){
        while(left<right){
            if(s[left]!= s[right])
            return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(string &s , int index){
        if(index==s.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int end = index; end<s.size(); end++){
            if(isPalindrome(s,index,end)){
                temp.push_back(s.substr(index, end-index+1));
                solve(s,end+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
        
    }
};