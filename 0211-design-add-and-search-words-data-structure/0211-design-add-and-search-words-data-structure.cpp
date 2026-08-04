class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode(){
        isEnd=false;

        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->child[idx]== NULL){
                node -> child[idx] = new TrieNode();
            }
            node = node -> child[idx];
        }

        node-> isEnd = true;
    }

    bool dfs (TrieNode* node , string &word , int index){
        if(index==word.size())
            return node->isEnd;
        char ch = word[index];

        if(ch!='.'){
            int idx = ch-'a';

            if(node->child[idx]==NULL)
                return false;

            return dfs( node->child[idx], word, index+1 );
        }

        for(int i=0;i<26;i++){
            if(node->child[i]){
                if(dfs(node -> child[i] , word , index+1))
                 return true;
            }
        }

        return false;
    }
    
    bool search(string word) {
        return dfs(root , word , 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */