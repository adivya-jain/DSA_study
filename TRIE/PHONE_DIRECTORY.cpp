class TrieNode{
    public:
    char data;
    TrieNode* childrens[26];
    bool isTerminal;

    TrieNode(char d)
    {
        data = d;
        for(int i = 0;i<26;i++)
        {
            childrens[i] = NULL;
        }
        isTerminal = false;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie(char ch) { root = new TrieNode(ch); }
    void insertUtil(TrieNode* root,string word)
    {
    if(word.length() == 0) {root->isTerminal = true; return;} 
        
        // ASSUMING ONLY CAPITALIZED WORD WERE GIVEN
        int index = word[0] - 'a';

        TrieNode *child;
        //present
        if(root->childrens[index]!=NULL)
        {
            child = root->childrens[index];
            
        }//absent
        else{
            child = new TrieNode(word[0]);
            root->childrens[index] = child;
            
        }
        insertUtil(child,word.substr(1)); 

    }
    void insertWord(string word)
    {
        insertUtil(root,word);
    }
    void printSuggestion(TrieNode* curr,vector<string>&temp,string prefix)
{
    if(curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    for(char ch = 'a';ch <='z' ; ch++)
    {
        TrieNode* next = curr->childrens[ch-'a'];

        if(next!=NULL)
        {
            prefix.push_back(ch);
            printSuggestion(next, temp, prefix);
            prefix.pop_back();
        }
    }
}
vector<vector<string>> querySuggestion(string str)
{
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix;
    for(int i = 0;i<str.length();i++)
    {
        char lastchar = str[i];

        prefix.push_back(lastchar);
        TrieNode* curr = prev->childrens[lastchar - 'a'];

        //if not found
        if(curr == NULL)
        {
            break;
        }
        //if found
        vector<string> temp;
        printSuggestion(curr, temp,prefix);
        output.push_back(temp);
        temp.clear();
        prev = curr;
        
    }

    return output;
}

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* t = new Trie('\0');
    for (int i = 0; i < contactList.size(); i++) {
            t->insertWord(contactList[i]);
        }


        return t->querySuggestion(queryStr);
}