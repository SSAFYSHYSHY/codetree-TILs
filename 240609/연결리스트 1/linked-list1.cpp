#include <iostream>
#include <string>

using namespace std;

string s, S;
int N;

struct Node {
	string data;
	Node* prev, * next;
	Node(string data) : data(data), prev(nullptr), next(nullptr) {}
};

void Insert_Front(Node* u, Node* new_u) {
	new_u->prev = u->prev;
	new_u->next = u;

	if (nullptr != new_u->prev) {
		new_u->prev->next = new_u;
	}
	if (nullptr != new_u->next) {
		new_u->next->prev = new_u;
	}
}

void Insert_Back(Node* u, Node* new_u) {
	new_u->prev = u;
	new_u->next = u->next;

	if (nullptr != new_u->prev) {
		new_u->prev->next = new_u;
	}
	if (nullptr != new_u->next) {
		new_u->next->prev = new_u;
	}
}

void Pop_front(Node*& u) {
	if (nullptr != u->prev) {
		u = u->prev;
	}
}

void Pop_back(Node*& u) {
	if (nullptr != u->next) {
		u = u->next;
	}
}

int main() {
	cin >> S >> N;

	Node* node = new Node(S);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			cin >> s;
			Node* new_node = new Node(s);

			Insert_Front(node, new_node);
		}

		else if (a == 2) {
			cin >> s;
			Node* new_node = new Node(s);

			Insert_Back(node, new_node);
		}

		else if (a == 3) {
			Pop_front(node);
		}
		else if (a == 4) {
			Pop_back(node);
		}

		if (nullptr == node->prev && nullptr != node->next) {
			cout << "(NULL) " << node->data << " " << node->next->data << "\n";
		}
		else if (nullptr != node->prev && nullptr == node->next) {
			cout << node->prev->data << " " << node->data << " (NULL)\n";
		}
		else if (nullptr == node->prev && nullptr == node->next) {
			cout << "(NULL) " << node->data << " (NULL)\n";
		}

		else {
			cout << node->prev->data << " " << node->data << " " << node->next->data << "\n";
		}
	}



}