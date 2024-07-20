class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childrenCount;
    bool isTerminal;

    TrieNode(char d) {
        data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childrenCount = 0;
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie(char ch) { root = new TrieNode(ch); }
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // ASSUMING ONLY CAPITALIZED WORD WERE GIVEN
        int index = word[0] - 'a';

        TrieNode* child;
        // present
        if (root->children[index] != NULL) {
            child = root->children[index];

        } // absent
        else {
            child = new TrieNode(word[0]);
            root->childrenCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) { insertUtil(root, word); }
     void lcp(string str, string& ans) {
        TrieNode* current = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (current->childrenCount == 1 && !current->isTerminal) {
                ans += ch;
                int index = ch - 'a';
                current = current->children[index];
            } else {
                break;
            }
        }
    }
};

class Solution {

public:
    string longestCommonPrefix(vector<string>& strs) {

        Trie* t = new Trie('\0');

        for (int i = 0; i < strs.size(); i++) {
            if(strs[i].length() == 0) // missing check to return in cases where the string is empty
                return ""; 
            t->insertWord(strs[i]);
        }

        string ans = "";
        string first = strs[0];
        t->lcp(first, ans);
        return ans;
    }
};