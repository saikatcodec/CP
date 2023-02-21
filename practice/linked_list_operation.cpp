#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

node *takeInput(node *prevNode) {
    node *newNode = (node *)malloc(sizeof(node));
    int data;
    cout << "Enter data: ";
    cin >> data;

    newNode->data = data;
    newNode->next = NULL;

    if (prevNode == NULL) {
        head = newNode;
    } else if (prevNode->next == NULL) {
        prevNode->next = newNode;
    }

    return newNode;
}

void printList() {
    node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void atBegining() {
    node *newNode = (node *)malloc(sizeof(node));
    int data;
    cout << "Enter data at begining: ";
    cin >> data;

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void atEnd() {
    node *newNode = (node *)malloc(sizeof(node));
    int data;
    cout << "Enter data at end: ";
    cin >> data;

    newNode->data = data;
    newNode->next = NULL;

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void atPosition(int pos) {
    node *temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }

    
}

int main() {
    node *temp = NULL;
    int n;
    cout << "Numbers of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        temp = takeInput(temp);
    }

    atBegining();
    atEnd();

    cout << "Printing the list: ";
    printList();

    // TODO delete the list
    return 0;
}