#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string data) : data(data), prev(nullptr), next(nullptr) {}
};

void Connect(Node* s, Node* e) {
    if (s != nullptr) s->next = e;
    if (e != nullptr) e->prev = s;
}

void Pop(Node* u) {
    Connect(u->prev, u->next);
    u->prev = u->next = nullptr;
}

void Input(Node* s, Node *e) {
    e->prev = s;
    e->next = s->next;

    if (nullptr != s->next) {
        s->next->prev = e;
    }
   
    s->next = e;
}

void Print(Node* node) {
    if (node->prev != nullptr && node->next != nullptr && node->prev->data == node->next->data) {
        cout << "-1\n";
        return;
    }
    if (node->prev == nullptr || node->next == nullptr) {
        cout << "-1\n";
        return;
    }

    if (node->prev != nullptr) cout << node->prev->data << " ";

    if (node->next != nullptr) cout << node->next->data << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    Node* head = new Node(s);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;

        Node* newNode = new Node(s);
        Connect(tail, newNode);
        tail = newNode;
    }
    Connect(tail, head);

    Node* currentNode = head;
    int idx = 0;
    while (m--) {
        int num;
        cin >> num;

        if (num == 1) {
            currentNode = currentNode->next;
            Print(currentNode);
        }
        else if (num == 2) {
            currentNode = currentNode->prev;
            Print(currentNode);
        }
        else if (num == 3) {
            Pop(currentNode->next);
            Print(currentNode);
        }
        else if (num == 4) {
            string s;
            cin >> s;
            Node* newNode2 = new Node(s);
            Input(currentNode, newNode2);
            Print(currentNode);
        }
    }

    return 0;
}