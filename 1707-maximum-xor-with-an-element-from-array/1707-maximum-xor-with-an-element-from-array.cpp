class TrieNode {
    public:
    TrieNode* child[2];
    TrieNode(){
        child[0] = nullptr;
        child[1] = nullptr;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* node = root;
        for(int i = 30 ; i >=0 ; i--){
            int bit = (num >> i)&1;
            if(node->child[bit] == nullptr)
             node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int getMaxXor(int num){
        TrieNode* node = root;
        int ans =0;
        for(int i =30 ; i>= 0 ; i--){
            int bit = (num >> i)&1;
            int opposite = 1 - bit;
            if(node->child[opposite]){
                ans |= (1<<i);
                node = node->child[opposite];
            }
            else{
                node = node->child[bit];
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin() , nums.end());
        vector<array<int,3>> q;
        for(int i =0 ; i < queries.size();i++){
            q.push_back({
                queries[i][0],
                queries[i][1],
                i
            });
        }

        sort(q.begin() , q.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        Trie trie;
        vector<int> ans(queries.size());
        int i = 0 ; 
        for(auto &query:q){
            int x = query[0];
            int m = query[1];
            int index = query[2];

            while(i < nums.size() && nums[i] <= m){
                trie.insert(nums[i]);
                i++;
            }
            if(i==0)
             ans[index] = -1;
            
            else
              ans[index] = trie.getMaxXor(x);
        }

        return ans;
    }
};