#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;

struct Node {
	int data;
	Node* prev, * next;
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

unordered_map<int, Node*> nodes;

void Print(Node* u) {
	cout << u->next->data << " " << u->prev->data << "\n";
}

void Remove(Node* u) {
	if (u->prev != nullptr) {
		u->prev->next = u->next;
	}
	if (u->next != nullptr) {
		u->next->prev = u->prev;
	}

	u->prev == nullptr;
	u->next == nullptr;
}

void Calc (int num) {
	for (int i = 0; i < n; i++) {
		if (nodes[i]->data == num) {
			Print(nodes[i]);

			Remove(nodes[i]);
		}
	}
}

void Connect(Node* s, Node* e) {
	if (nullptr != s) {
		s->next = e;
	}
	if (nullptr != e) {
		e->prev = s;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		nodes[i] = new Node(num);
	}
	for (int i = 0; i < n - 1; i++) {
		Connect(nodes[i], nodes[i + 1]);
	}

	Connect(nodes[n - 1], nodes[0]);

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		Calc(a);
	}


}