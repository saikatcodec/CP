#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

Tree<int>* takeInput() {
    int rootData;
    cout << "Enter Data ";
    cin >> rootData;
    Tree<int>* root = new Tree<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << " ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Tree<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printTree(Tree<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << ": ";
    for (auto node : root->children){
        cout << node->data << ",";
    }
    cout << endl;

    for (auto node : root->children) {
        printTree(node);
    }
}

int main()
{
    // Tree<int>* root = new Tree<int>(1);
    // Tree<int>* child1 = new Tree<int>(2);
    // Tree<int>* child2 = new Tree<int>(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    
    Tree<int>* root;
    root = takeInput();

    printTree(root);

    // TODO  delete the Tree
      
    return 0;
}