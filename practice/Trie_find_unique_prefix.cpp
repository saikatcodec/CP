#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool leaf;
    int cnt = 0;

    Node(char ch)
    {
        data = ch;
        leaf = false;
        cnt = 1;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string str)
    {
        Node *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            if (temp->children.count(ch))
            {
                temp->children[ch]->cnt += 1;
                temp = temp->children[ch];
            }
            else
            {
                Node *newIn = new Node(ch);
                temp->children[ch] = newIn;
                temp = newIn;
            }
        }

        temp->leaf = true;
    }

    string uniquePrefix(string str)
    {
        Node *temp = root;
        string ans = "";
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            ans.push_back(ch);

            if (temp->children[ch]->cnt == 1)
            {
                return ans;
            }
            else
            {
                temp = temp->children[ch];
            }
        }

        if (temp->cnt != 1)
        {
            ans = "-1";
        }
        return ans;
    }
};

int main()
{
    string arr[] = {"cobra", "duck", "dove", "dog", "cobras"};

    Trie tr;
    for (int i = 0; i < 5; i++)
    {
        tr.insert(arr[i]);
    }

    vector<string> ans;
    for (int i = 0; i < 5; i++)
    {
        string tmp = tr.uniquePrefix(arr[i]);
        ans.push_back(tmp);
    }

    for (auto el : ans)
    {
        cout << el << endl;
    }

    return 0;
}