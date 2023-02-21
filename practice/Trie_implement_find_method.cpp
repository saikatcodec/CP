#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    char data;
    unordered_map<char, Node *> children;
    bool leaf;

    Node(char data) {
        this->data = data;
        leaf = false;
    }
};

class Trie {
    Node *root;

   public:
    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (temp->children.count(ch)) {
                temp = temp->children[ch];
            } else {
                Node *single = new Node(ch);
                temp->children[ch] = single;
                temp = single;
            }
        }

        temp->leaf = true;
    }

    bool findWord(string word) {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (temp->children.count(ch) == 0) {
                return false;
            } else {
                temp = temp->children[ch];
            }
        }

        return temp->leaf;
    }
};

int main() {
    int n;
    cout << "Enter number of word: ";
    cin >> n;

    Trie t;
    string str[n];
    cout << "Enter word: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        t.insert(str[i]);
    }

    string key;
    cout << "Enter word to search: ";
    cin >> key;

    if (t.findWord(key)) {
        cout << "Present" << endl;
    } else {
        cout << "Absent" << endl;
    }

    return 0;
}