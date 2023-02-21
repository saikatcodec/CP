#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    char data;
    unordered_map<char, Node *> children;
    bool leaf;
    int cnt = 0;

    Node(char ch) {
        data = ch;
        leaf = false;
        cnt = 1;
    }
};

class Trie {
    Node *root;

   public:
    Trie() {
        root = new Node('\0');
    }

    void insert(string str) {
        Node *temp = root;
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];

            if (temp->children.count(ch)) {
                temp->children[ch]->cnt += 1;
                temp = temp->children[ch];
            } else {
                Node *newIn = new Node(ch);
                temp->children[ch] = newIn;
                temp = newIn;
            }
        }
    }
};

int main() {
    return 0;
}