/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Node {
private:
    unordered_map<char, Node*> links;
    bool isEnd;
public:
    Node() {
        isEnd = false;
    }

    bool containsKey(char c) {
        return links.find(c) != links.end();
    }

    void putLink(char c, Node* node) {
        links[c] = node;
    }

    Node* getLink(char c) {
        return links[c];
    }

    void setEnd() {
        isEnd = true;
    }

    bool checkEnd() {
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

    void insert(string word) {
        Node* currNode = root;
        for (char c : word) {
            if (!currNode->containsKey(c)) currNode->putLink(c, new Node());
            currNode = currNode->getLink(c);
        }
        currNode->setEnd();
    }

    bool searchPrefix(string word) {
        Node* currNode = root;
        for (char c : word) {
            if (!currNode->containsKey(c)) return false;
            currNode = currNode->getLink(c);
            if (currNode->checkEnd()) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie prefixTree;
        vector<string> result;
        
        sort(folder.begin(), folder.end());
        for (const string& path : folder) {
            if (!prefixTree.searchPrefix(path + '/')) {
                prefixTree.insert(path + '/');
                result.push_back(path);
            }
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
Author: M.R.Naganathan
*/
