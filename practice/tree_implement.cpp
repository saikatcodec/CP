#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInput() {
    int data;
    cout << "Enter root date: ";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);

    queue<TreeNode<int> *> pending;
    pending.push(root);

    while (!pending.empty()) {
        TreeNode<int> *front = pending.front();
        pending.pop();

        int child;
        cout << "Num of child of " << front->data << ": ";
        cin >> child;

        for (int i = 0; i < child; i++) {
            cout << "Enter children data of " << front->data << ": ";
            cin >> data;
            TreeNode<int> *children = new TreeNode<int>(data);
            front->children.push_back(children);
            pending.push(children);
        }
    }

    return root;
}

void printTree(TreeNode<int> *root) {
    queue<TreeNode<int> *> pending;
    pending.push(root);

    while (!pending.empty()) {
        TreeNode<int> *front = pending.front();
        pending.pop();

        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++) {
            cout << front->children[i]->data << ", ";
            pending.push(front->children[i]);
        }
        cout << endl;
    }
}

void preorder(TreeNode<int> *root) {
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root) {
    for (int i = 0; i < root->children.size(); i++) {
        postorder(root->children[i]);
    }

    cout << root->data << " ";
}

int numOfNode(TreeNode<int> *root) {
    int ans = 1;

    for (int i = 0; i < root->children.size(); i++) {
        ans += numOfNode(root->children[i]);
    }

    return ans;
}

int findHeight(TreeNode<int> *root) {
    int ans = 1;
    vector<int> pendingAns;

    for (int i = 0; i < root->children.size(); i++) {
        pendingAns.push_back(findHeight(root->children[i]));
    }

    if (root->children.size() > 0) {
        int maxAns = *max_element(pendingAns.begin(), pendingAns.end());
        ans += maxAns;
    }

    return ans;
}

void printAtDepth(TreeNode<int> *root, int k) {
    if (k == 0) {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++) {
        printAtDepth(root->children[i], k - 1);
    }
}

int coutLeaf(TreeNode<int> *root) {
    int ans = 0;
    if (root->children.size() == 0) {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++) {
        ans += coutLeaf(root->children[i]);
    }

    return ans;
}

// 1 2 2 3 2 4 5 2 6 7 0 0 0 0
// 1 3 2 3 4 2 4 5 3 6 7 8 0 0 0 0 2 10 11 0 0 3 12 13 14 0 0 2 15 16 0 0
int main() {
    TreeNode<int> *root;
    root = takeInput();

    // printTree(root);
    cout << endl;
    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    cout << "Num of node of tree: " << numOfNode(root) << endl;
    cout << "Height of a tree: " << findHeight(root) << endl;
    // int k;
    // cout << "Enter depth: ";
    // cin >> k;
    // cout << "Print node at depth " << k << ": ";
    // printAtDepth(root, k);
    // cout << endl;
    cout << "Leaf node of the tree: " << coutLeaf(root) << endl;
    delete root;

    return 0;
}