#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BTreeNode {
   public:
    T data;
    BTreeNode<T> *leftNode;
    BTreeNode<T> *rightNode;

    BTreeNode(T data) {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }

    ~BTreeNode() {
        delete leftNode;
        delete rightNode;
    }
};

// Recursively
BTreeNode<int> *takeInput() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    BTreeNode<int> *root = new BTreeNode<int>(data);
    BTreeNode<int> *leftChild = takeInput();
    BTreeNode<int> *rightChild = takeInput();

    root->leftNode = leftChild;
    root->rightNode = rightChild;

    return root;
}

// Recursively
void printTree(BTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << ": ";
    if (root->leftNode) {
        cout << "L " << root->leftNode->data << ", ";
    }
    if (root->rightNode) {
        cout << "R " << root->rightNode->data;
    }
    cout << endl;

    printTree(root->leftNode);
    printTree(root->rightNode);
}

// Leve-wise
BTreeNode<int> *takeInputLevel() {
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    BTreeNode<int> *root = new BTreeNode<int>(rootData);

    queue<BTreeNode<int> *> pending;
    pending.push(root);

    while (!pending.empty()) {
        BTreeNode<int> *front = pending.front();
        pending.pop();

        int lData, rData;
        cout << "Enter left child of " << front->data << ": ";
        cin >> lData;
        if (lData != -1) {
            BTreeNode<int> *leftChild = new BTreeNode<int>(lData);
            front->leftNode = leftChild;
            pending.push(leftChild);
        }

        cout << "Enter right child of " << front->data << ": ";
        cin >> rData;
        if (rData != -1) {
            BTreeNode<int> *rightChild = new BTreeNode<int>(rData);
            front->rightNode = rightChild;
            pending.push(rightChild);
        }
    }

    return root;
}

// Level-wise
void printTreeLevel(BTreeNode<int> *root) {
    queue<BTreeNode<int> *> pending;
    pending.push(root);

    while (!pending.empty()) {
        BTreeNode<int> *front = pending.front();
        pending.pop();

        cout << front->data << ": ";
        if (front->leftNode) {
            cout << "L " << front->leftNode->data << ", ";
            pending.push(front->leftNode);
        }
        if (front->rightNode) {
            cout << "R " << front->rightNode->data;
            pending.push(front->rightNode);
        }
        cout << endl;
    }
}

int countNode(BTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNode(root->leftNode) + countNode(root->rightNode);
}

int findHeight(BTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + max(findHeight(root->leftNode), findHeight(root->rightNode));
}

void inorder(BTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->leftNode);
    cout << root->data << " ";
    inorder(root->rightNode);
}

void preorder(BTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->leftNode);
    preorder(root->rightNode);
}

void postorder(BTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->leftNode);
    postorder(root->rightNode);
    cout << root->data << " ";
}

BTreeNode<int> *helperBuildTree(int *pre, int *in, int inS, int inE, int preS, int preE) {
    if (inS > inE) {
        return NULL;
    }

    int rootData = pre[preS];
    BTreeNode<int> *root = new BTreeNode<int>(rootData);

    int rootIndex = -1;
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = lPreS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = rPreE;

    root->leftNode = helperBuildTree(pre, in, lInS, lInE, lPreS, lPreE);
    root->rightNode = helperBuildTree(pre, in, rInS, rInE, rPreS, rPreE);

    return root;
}

BTreeNode<int> *buildTree(int *pre, int *in, int size) {
    return helperBuildTree(pre, in, 0, size - 1, 0, size - 1);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    // BTreeNode<int> *root = takeInput();
    BTreeNode<int> *root;
    int n;
    cout << "NUmber of nodes: ";
    cin >> n;

    int pre[n], in[n];
    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    root = buildTree(pre, in, n);

    cout << endl;
    printTree(root);

    cout << "Num of node in the tree: " << countNode(root) << endl;
    cout << "Height of the tree: " << findHeight(root) << endl;
    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal of the tree: ";
    preorder(root);
    cout << endl;
    cout << "Postorder traversal of the tree: ";
    postorder(root);
    cout << endl;

    delete root;

    return 0;
}