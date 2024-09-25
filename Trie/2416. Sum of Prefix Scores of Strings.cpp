/*------------------------------
  Time Complexity: O(n * maxLen)
  Space Complexity: O(maxLen)
---------------------------------*/

class Node {
private:
    Node* links[26];
    bool isEnd;
    int freq;
public:
    Node() {
        isEnd = false;
        freq = 0;
        for (int i = 0; i < 26; ++i) links[i] = NULL;
    }

    bool containsKey(char c) {
        return (links[c - 'a'] != NULL);
    }

    void putLink(char c, Node* node) {
        links[c - 'a'] = node;
    }

    Node* getLink(char c) {
        return links[c - 'a'];
    }

    bool checkEnd() {
        return isEnd;
    }

    void incrementCount() {
        freq += 1;
    }

    int getFreq() {
        return freq;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertString(string &word) {
        Node* currNode = root;
        for (int i = 0; i < word.length(); i++) {
            if (!(currNode->containsKey(word[i]))) currNode->putLink(word[i], new Node());
            currNode = currNode->getLink(word[i]);
            currNode->incrementCount();
        }
    }

    int getTotalScore(string &word) {
        Node* currNode = root;
        int totalScore = 0;
        for (int i = 0; i < word.length(); i++) {
            currNode = currNode->getLink(word[i]);
            totalScore += (currNode -> getFreq());
        }
        return totalScore;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        vector<int> totalScore(words.size(), 0);

        for (string& word : words) trie->insertString(word);
        for (int i = 0; i < words.size(); i++) {
            totalScore[i] = trie->getTotalScore(words[i]);
        }
        return totalScore;
    }
};

/*
Question Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
Author: M.R.Naganathan
*/
