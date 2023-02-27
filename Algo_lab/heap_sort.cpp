#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // To delete the node
    ~Node() {
        delete left;
        delete right;
    }
};

void insert(Node *&root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void print(Node *root) {
    Node *temp = root;

    if (temp == NULL) {
        return;
    }

    cout << temp->data << ": ";
    if (temp->left) {
        cout << "L" << temp->left->data;
    }
    if (temp->right) {
        cout << " R" << temp->right->data;
    }
    cout << endl;

    print(temp->left);
    print((temp->right));
}

int main() {
    int arr[] = {10, 7, 9, 8, 12, 11, 13};
    Node *root;

    Node *ten = new Node(10);
    Node *seven = new Node(7);
    Node *nine = new Node(9);
    Node *eight = new Node(8);
    Node *tweleve = new Node(12);
    Node *eleven = new Node(11);
    Node *thirteen = new Node(13);

    tweleve->left = eleven;
    tweleve->right = thirteen;

    eight->left = seven;
    eight->right = nine;

    ten->left = eight;
    ten->right = tweleve;

    root = ten;

    print(root);

    return 0;
}