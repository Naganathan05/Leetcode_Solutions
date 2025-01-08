/*----------------------------
  Time Complexity: O(n * L)
  Space Complexity: O(n * L)
------------------------------*/

class Node {
private:
    Node* links[26];
public:
    int isEnd;
    Node() {
        for(int i = 0; i <= 25; i++) links[i] = NULL;
        isEnd = 0;
    }

    bool containsLink(char c){
        return links[c - 'a'] != NULL;
    }

    Node* getLink(char c) {
        return links[c - 'a'];
    }

    void putLink(char c, Node* node){
        links[c - 'a'] = node;
        return;
    }

    int checkEnd(){
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
        currNode -> isEnd += 1;
        return;
    }

    map<string, int> searchPrefix(string &word){
        string currString = "";
        Node* currNode = root;
        map<string, int> matchedPrefix;
        for(int i = 0; i <= word.length() - 1; i++){
            if(!(currNode -> containsLink(word[i]))) return matchedPrefix;
            currString += word[i];
            currNode = currNode -> getLink(word[i]);
            if(currNode -> checkEnd()) matchedPrefix[currString] = currNode -> isEnd;
        }
        return matchedPrefix;
    }

    int searchSuffix(string &word, map<string, int> &matchedPrefixes){
        int numErases = 0;
        string currString = "";
        for(int i = word.length() - 1; i >= 0; i--){
            currString = word[i] + currString;
            if(matchedPrefixes.find(currString) != matchedPrefixes.end()){
                numErases += matchedPrefixes[currString];
            }
        }
        return numErases;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Trie* prefixTree = new Trie();
        int numPairs = 0;
        for(int i = 0; i <= words.size() - 1; i++){
            string currString = words[i];
            map<string, int> matchedPrefixes = prefixTree -> searchPrefix(currString);
            // for(auto itr = matchedPrefixes.begin(); itr != matchedPrefixes.end(); itr++){
            //     cout << *itr << " ";
            // }
            // cout << endl;
            numPairs += (prefixTree -> searchSuffix(currString, matchedPrefixes));
            prefixTree -> insertWord(currString);
        }
        return numPairs;
    }
};

/*
Question Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
Author: M.R.Naganathan
*/
