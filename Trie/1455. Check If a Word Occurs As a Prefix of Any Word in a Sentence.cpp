/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Node {
private:
    Node* links[26];
    bool isEnd;
public:
    Node() {
        for(int i = 0; i <= 25; i++) links[i] = NULL;
        isEnd = false;
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
    Trie() {
        root = new Node();
    }

    void insert(string &word){
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsLink(word[i]))) currNode -> putLink(word[i], new Node());
            currNode = currNode -> getLink(word[i]);
        }
        currNode -> setEnd();
        return;
    }

    bool prefixSearch(string &prefix){
        Node* currNode = root;
        for(int i = 0; i <= prefix.length() - 1; i++){
            if(!(currNode -> containsLink(prefix[i]))) return false;
            currNode = currNode -> getLink(prefix[i]);
        }
        return true;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        Trie* prefixTree = new Trie();
        string currWord = "";
        int startIndex = 1;
        for(int i = 0; i <= sentence.length() - 1; i++){
            if(sentence[i] == ' '){
                prefixTree -> insert(currWord);
                if(prefixTree -> prefixSearch(searchWord)) return startIndex;
                currWord = "";
                startIndex += 1;
                continue;
            }
            currWord += sentence[i];
        }
        prefixTree -> insert(currWord);
        if (prefixTree -> prefixSearch(searchWord)) return startIndex;
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
Author: M.R.Naganathan
*/
