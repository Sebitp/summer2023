#include<string>
using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto &chr : word){
            int i = chr- 'a';
            if (!temp->child[i]){
                temp->child[i] = new TrieNode();
            }
            temp = temp->child[i];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto &chr : word){
            int i = chr - 'a';
            if (!temp->child[i]) return false;
            temp = temp->child[i];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto &chr : prefix){
            int i = chr - 'a';
            if (!temp->child[i]) return false;
            temp = temp->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */