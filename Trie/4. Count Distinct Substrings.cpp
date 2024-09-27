/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------*/

class Node {
private:
    Node* links[26];
    bool isEnd;
public:
    Node() {
        isEnd = false;
        for(int i = 0; i <= 25; i++) links[i] = NULL;
    }

    bool containsLink(char c){
        return links[c - 'a'] != NULL;
    }

    void putLink(char c, Node* node){
        links[c - 'a'] = node;
        return;
    }

    Node* getLink(char c){
        return links[c - 'a'];
    }

    bool checkEnd(){
        return isEnd;
    }

    void setEnd(){
        isEnd = true;
        return;
    }
};

class Trie {
private:
    Node* root;
    int numStrings;
public:
    Trie() {
        root = new Node();
        numStrings = 0;
    }

    void insertString(string &word){
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsLink(word[i]))) currNode -> putLink(word[i], new Node());
            currNode = currNode -> getLink(word[i]);
        }
        if(!(currNode -> checkEnd())){
            currNode -> setEnd();
            numStrings += 1;
        }
        return;
    }

    int getNumStrings(){
        return numStrings;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie* prefixTree = new Trie();
    for(int i = 0; i <= s.length() - 1; i++){
        string currString = "";
        for(int j = i; j <= s.length() - 1; j++){
            currString += s[j];
            prefixTree -> insertString(currString);
        }
    }
    return prefixTree -> getNumStrings() + 1;
}

/*
Question Link: https://www.naukri.com/code360/problems/count-distinct-substrings_985292/
Author: M.R.Naganathan
*/
