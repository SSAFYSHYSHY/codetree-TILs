#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    Node* left;
    int idx;
    Node* right;

    Node(int idx) : idx(idx), left(nullptr), right(nullptr) {}
};

void connect(Node* n1, Node* n2) {
    if (n1 != nullptr) {
        n1->right = n2;
    }
    if (n2 != nullptr) {
        n2->left = n1;
    }
}

void popAndInterchange(Node* n1, Node* n2, Node* n3, Node* n4) {
    bool check = false;
    Node* n1Left = n1->left;
    Node* n2Right = n2->right;
    Node* n3Left = n3->left;
    Node* n4Right = n4->right;

    if (n2->right == n3) {
        check = true;
    }

    connect(n1->left, n2->right);
    n1->left = n2->right = nullptr;
    connect(n3->left, n4->right);
    n3->left = n4->right = nullptr;

    if (check) {
        connect(n1Left, n3);
        connect(n2, n4Right);
        connect(n4, n1);
    } else {
        connect(n4, n2Right);
        connect(n1Left, n3);
        connect(n3Left, n1);
        connect(n2, n4Right);
    }
}

int main() {
    unordered_map<int, Node*> nodeMap;

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        Node* node = new Node(i);
        nodeMap[i] = node;
        if (nodeMap.find(i - 1) != nodeMap.end()) {
            connect(nodeMap[i - 1], nodeMap[i]);
        }
    }

    Node* head = nodeMap[1];
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        popAndInterchange(nodeMap[a], nodeMap[b], nodeMap[c], nodeMap[d]);
        if (nodeMap[c]->left == nullptr) {
            head = nodeMap[c];
        } else if (nodeMap[a]->left == nullptr) {
            head = nodeMap[a];
        }
    }

    // 출력부
    while (head->right != nullptr) {
        cout << head->idx << " ";
        head = head->right;
    }
    cout << head->idx;

    // 메모리 해제
    for (auto& kv : nodeMap) {
        delete kv.second;
    }
    nodeMap.clear();

    return 0;
}