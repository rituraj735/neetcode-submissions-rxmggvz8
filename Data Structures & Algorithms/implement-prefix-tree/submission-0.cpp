class Node{
    public: 
        unordered_map<char, Node*> mp;
        bool endOfWord;
   
        Node(){
            endOfWord = false;
        }

};
class PrefixTree {
private: 
    Node* root;
    
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->mp.find(word[i]) == node->mp.end()){
                node->mp[word[i]] = new Node();
            }
            node = node->mp[word[i]];
        }
       node->endOfWord = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->mp.find(word[i]) != node->mp.end()){
                node = node->mp[word[i]];
            }
            else{ return false;}
        }
        if(node->endOfWord){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
         Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(node->mp.find(prefix[i]) != node->mp.end()){
                node = node->mp[prefix[i]];
            }
            else{ return false;}
        }
        if(node) return true;
        return false;
    }
};
