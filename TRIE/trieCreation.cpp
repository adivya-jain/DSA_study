#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        data = d;
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode *root;
Trie()
{
    root = new TrieNode('\0');
}
    void insertUtil(TrieNode* root,string word)
    {
    if(word.length() == 0) {root->isTerminal = true; return;} 
        
        // ASSUMING ONLY CAPITALIZED WORD WERE GIVEN
        int index = word[0] - 'A';

        TrieNode *child;
        //present
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
            
        }//absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            
        }
        insertUtil(child,word.substr(1)); 

    }
    void insertWord(string word)
    {
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode *root,string word)
    {
        if(word.length() == 0)
        {
            if(root->isTerminal == true)
            {
                return true;
            }
        }
        TrieNode* child;
        int index = word[0]-'A';
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else {
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }
// void deleteUtil(TrieNode* root, string word)
// {
//     if(word.length() == 0)
//     {
//         if(root->isTerminal == true)
//         {
//             cout<<"WORD DISCONNECTED";
//             root->isTerminal = false;
//             return;
//         }
//     }

//         int index = word[0] - 'A';
//         TrieNode* child;
//         if(root->children[index] != NULL){
//         child = root->children[index];
//         }
//         else{
//             cout<<"WORD NOT FOUND";
//             return;
//         }

//         deleteUtil(child,word.substr(1));

//     }

//     void deleteWord(string word)
//     {
//         deleteUtil(root,word);
//     }

bool deleteUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            // Word found
            if (root->isTerminal) {
                root->isTerminal = false;
                // Check if root has any children
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Node has children, so don't delete this node
                    }
                }
                return true; // Node can be deleted
            } else {
                return false; // Word not found
            }
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];
        if (child == NULL) {
            return false; // Word not found
        }

        bool shouldDeleteCurrentNode = deleteUtil(child, word.substr(1));

        if (shouldDeleteCurrentNode) {
            cout<<"deleted word "<<root->children[index]->data<<endl;
            delete child;;
            root->children[index] = NULL;
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    return false; // Node has children, so don't delete this node
                }
            }
            return !root->isTerminal; // Return true if root is not a terminal node
        }
        return false;
    }

    void deleteWord(string word) {
        deleteUtil(root, word);
    }
};
int main()
{
    Trie *t = new Trie();
    
    t->insertWord("ADIVYA");
    t->insertWord("YOO");
    t->insertWord("ADITI");

    cout<< t->searchWord("JAINO")<<endl;
    t->deleteWord("JAIHIND");cout<<endl;
    t->deleteWord("YOO");cout<<endl;
    cout<< t->searchWord("ADIVYA")<<endl;
}