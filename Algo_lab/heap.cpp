#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node*& root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }

    if (data < root->data) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

void heapify(Node* root, int n) {
    if (root == NULL) {
        return;
    }

    int largest = root->data;
    Node* largestNode = root;

    if (root->left != NULL && root->left->data > largest) {
        largest = root->left->data;
        largestNode = root->left;
    }

    if (root->right != NULL && root->right->data > largest) {
        largest = root->right->data;
        largestNode = root->right;
    }

    if (largestNode != root) {
        swap(root->data, largestNode->data);
        heapify(largestNode, n);
    }
}

void convertToHeap(Node* root, int n) {
    if (root == NULL) {
        return;
    }

    convertToHeap(root->left, n);
    convertToHeap(root->right, n);
    heapify(root, n);
}

void heapSort(int arr[], int n) {
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        insertNode(root, arr[i]);
    }

    convertToHeap(root, n);

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = root->data;
        root->data = arr[0];
        heapify(root, i);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
