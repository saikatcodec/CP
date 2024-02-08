#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, int v) {
    Node *newnode = new Node(v);
    if (head == NULL) {
        head = newnode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    // tmp ekhon last node e
    tmp->next = newnode;
}

void print_linked_list(Node *head) {
    Node *tmp = head;
    cout << "Your linked list:" << endl;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;

    cout << "Option 1: Insert at tail" << endl;
    int op;
    cin >> op;
    if (op == 1) {
        cout << "enter value:" << endl;
        int v;
        cin >> v;
        insert_at_tail(head, v);
    }
    print_linked_list(head);
    return 0;
}