class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        is_end = false;
        for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *ptr = this;
        for (size_t i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!ptr->children[index]) {
                ptr->children[index] = new Trie();
            }
            ptr = ptr->children[index];
        }
        ptr->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *ptr = this;
        for (size_t i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!ptr->children[index]) {
                return false;
            }
            ptr = ptr->children[index];
        }
        return (ptr != nullptr && ptr->is_end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *ptr = this;
        for (size_t i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (!ptr->children[index]) {
                return false;
            }
            ptr = ptr->children[index];
        }
        return true;
    }

private:
    const static int ALPHABET_SIZE = 26;
    Trie *children[ALPHABET_SIZE];
    bool is_end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
