
    /*
    Time complexity : O(n * L)
    Space complexity : O(n * L)
    */


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
    Trie(){
        root = new Node();
        root -> setEnd();
    }

    void insertString(string &word){
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsLink(word[i]))) currNode -> putLink(word[i], new Node());
            currNode = currNode -> getLink(word[i]);
        }
        currNode -> setEnd();
        return;
    }

    bool getLongestWord(string &word){
        Node* currNode = root;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> checkEnd()) || !(currNode -> containsLink(word[i]))) return false;
            currNode = currNode -> getLink(word[i]);
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        int maxLen = 0;
        string maxLengthString = "";
        Trie* prefixTree = new Trie();
        for(int i = 0; i <= words.size() - 1; i++) prefixTree -> insertString(words[i]);
        for(string& str : words){
            if(prefixTree -> getLongestWord(str)){
                if(maxLen < str.length()){
                    maxLen = str.length();
                    maxLengthString = str;
                }
                else if(maxLen == str.length()){
                    if(maxLengthString > str) maxLengthString = str;
                }
            }   
        }
        return maxLengthString;
    }
};


    /*
    Author : Naganathan05
    Question Link : https://leetcode.com/problems/longest-word-in-dictionary/
    */

    