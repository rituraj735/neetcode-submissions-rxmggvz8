class TrieNode{
    public:
        vector<TrieNode*> children;
        bool endOfWord = false;
    
    TrieNode(): children(26, NULL), endOfWord(false) {}
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word){
            int i = c - 'a';
            if(cur->children[i] == NULL) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;

        for(int i=j; i<word.size(); i++){
            char c = word[i];
            if(c=='.'){
                for(TrieNode* child: cur->children){
                    if(child != NULL && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            } else {
                if (cur->children[c-'a'] == NULL){
                    return false;
                }
                cur = cur->children[c-'a'];
            }
        }
        return cur->endOfWord;
    }
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
