class TrieNode{
public:
      TrieNode* child[26];
      bool isEnd;
      TrieNode(){
        isEnd = false;
        for(int i =0 ; i < 26 ; i++){
            child[i] = NULL;
        }
      }
};

class Solution {
public:
    TrieNode* root=new TrieNode();
    void insert(string word){
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->child[idx] == NULL){
                node -> child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node-> isEnd = true;
    }

    string getRoot(string word){
        TrieNode* node=root;
        string ans="";

        for(char ch:word){
            int idx=ch-'a';

            if(node->child[idx]==NULL)
                return word;

            ans += ch;

            node=node->child[idx];

            if(node->isEnd)
                return ans;
        }

        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string word:dictionary)
            insert(word);

        stringstream ss(sentence);
        string word;
        string ans="";

        while(ss>>word){
            ans+=getRoot(word);
            ans+=" ";
        }

        ans.pop_back();

        return ans;
    }
};