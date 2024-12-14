/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Node {
public:
    unordered_map<char, Node*> links;
    bool isEnd;
    Node () {
        isEnd = false;
    }

    bool containsLink(char c){
        return links.find(c) != links.end();
    }

    void putLink(char c, Node* node){
        links[c] = node;
        return;
    }

    Node* getLink(char c){
        return links[c];
    }

    void setEnd(){
        isEnd = true;
        return;
    }

    bool checkEnd(){
        return isEnd;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie () {
        root = new Node();
    }

    void insertWord(string &word){
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsLink(word[i]))) currNode -> putLink(word[i], new Node());
            currNode = currNode -> getLink(word[i]);
        }
        currNode -> setEnd();
        return;
    }

    bool DFS(string &searchWord, int i, Node* currNode) {
        if (i == searchWord.length()) return currNode->checkEnd();
        
        if (searchWord[i] == '.') {
            for (auto &link : currNode -> links) {
                if (DFS(searchWord, i + 1, link.second)) return true;
            }
            return false;
        } 
        else {
            if (currNode->containsLink(searchWord[i])) return DFS(searchWord, i + 1, currNode->getLink(searchWord[i]));
            else return false;
        }
    }


    bool searchWord(string &word){
        return DFS(word, 0, root);
    }
};

class WordDictionary {
private:
    Trie* prefixTree;
public:
    WordDictionary() {
        prefixTree = new Trie(); 
    }
    
    void addWord(string word) {
        prefixTree -> insertWord(word);
        return;
    }
    
    bool search(string word) {
        return prefixTree -> searchWord(word);
    }
};

/*
Question Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
Author: M.R.Naganathan
*/
