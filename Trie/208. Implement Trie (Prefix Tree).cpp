/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Node {
private:
    Node* links[26];
    bool flag = false;
public:
    bool containsKey(char c){
        return (links[c - 'a'] != NULL);
    }
    
    void putLink(char c, Node* node){
        links[c - 'a'] = node;
    }

    Node* getLink(char c){
        return links[c - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool checkEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsKey(word[i]))) currNode -> putLink(word[i], new Node());
            currNode = currNode -> getLink(word[i]);
        }
        currNode -> setEnd();
    }
    
    bool search(string word) {
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsKey(word[i]))) return false;
            currNode = currNode -> getLink(word[i]);
        }
        return currNode -> checkEnd();
    }
    
    bool startsWith(string prefix) {
        Node* currNode = root;
        for(int i = 0; i <= prefix.length() - 1; i++){
            if(!(currNode -> containsKey(prefix[i]))) return false;
            currNode = currNode -> getLink(prefix[i]);
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/implement-trie-prefix-tree/
Author: M.R.Naganathan
*/
