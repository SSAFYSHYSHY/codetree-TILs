#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, Q;

struct Node {
	int data;
	Node* prev, * next;
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}

};

unordered_map<int, Node*> nodes;

void New_Node(Node* u) {
	if (u->prev != nullptr) {
		u->prev->next = u->next;
	}
	if (u->next != nullptr) {
		u->next->prev = u->prev;
	}

	u->prev = nullptr;
	u->next = nullptr;
}

void InsertFront(Node* u, Node* new_u) {
	new_u->prev = u->prev;
	new_u->next = u;

	if (nullptr != new_u->prev) {
		new_u->prev->next = new_u;
	}
	if (nullptr != new_u->next) {
		new_u->next->prev = new_u;
	}
}

void InsertBack(Node* u, Node* new_u) {
	new_u->next = u->next;
	new_u->prev = u;

	if (nullptr != new_u->prev) {
		new_u->prev->next = new_u;
	}
	if (nullptr != new_u->next) {
		new_u->next->prev = new_u;
	}
}

void Print(Node* u) {
	string s = "0";

	if (u->prev == nullptr) cout << s << " ";
	else cout << u->prev->data << " ";

	if (u->next == nullptr) cout << s << "\n";
	else cout << u->next->data << "\n";
}

int main() {
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		nodes[i] = new Node(i);
	}

	for (int i = 0; i < Q; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			int num;
			cin >> num;

			New_Node(nodes[num]);
		}
		else if (a == 2) {
			int i, j;
			cin >> i >> j;

			InsertFront(nodes[i], nodes[j]);
		}
		else if (a == 3) {
			int i, j;
			cin >> i >> j;

			InsertBack(nodes[i], nodes[j]);
		}
		else {
			int num;
			cin >> num;

			Print(nodes[num]);
		}
	}

	string s = "0";

	for (int i = 1; i <= N; i++) {
		if (nodes[i]->next == nullptr) cout << s << " ";
		else cout << nodes[i]->next->data << " ";
	}
}