/*--------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

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
        return (links[c - 'a'] != NULL);
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
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
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
};

class Solution {
public:
    int ValidateStrings(string &target, int i, Trie* prefixTree, vector<int> &dp){
        if(i == target.length()) return 0;
        if(dp[i] != -1) return dp[i];

        int minPartition = 1e9;
        string currString = "";
        Node* currNode = prefixTree -> root;
        for(int j = i; j <= target.length() - 1; j++){
            int currPartition = 1e9;
            currString += target[j];
            if(currNode -> containsLink(target[j])) currPartition = 1 + ValidateStrings(target, j + 1, prefixTree, dp);
            else break;
            currNode = currNode -> getLink(target[j]);
            minPartition = min(minPartition, currPartition);
        }
        return dp[i] = minPartition;
    }

    int minValidStrings(vector<string>& words, string target) {
        Trie* prefixTree = new Trie();
        for(string& word : words) prefixTree -> insertString(word);
        vector<int> dp(target.length(), -1);
        int minStrings = ValidateStrings(target, 0, prefixTree, dp);
        if(minStrings >= 1e9) return -1;
        return minStrings;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/
Author: M.R.Naganathan
*/
