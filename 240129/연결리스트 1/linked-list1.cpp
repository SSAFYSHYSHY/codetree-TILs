#include <iostream>
#include <string>

using namespace std;

string S_init;
int N;
string s;

//하나의 정수를 가지고 있는 노드.
struct Node {
	string data;
	Node* prev, * next;
	Node(string data) : data(data), prev(nullptr), next(nullptr) {}
};

void Insert_front(Node* u, Node* new_u) {
	new_u->prev = u->prev;
	new_u->next = u;

	if (nullptr != new_u->prev) {
		new_u->prev->next = new_u;
	}
	if (nullptr != new_u->next) {
		new_u->next->prev = new_u;
	}
}

void Insert_back(Node* u, Node* new_u) {
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
	cin >> S_init;
	cin >> N;

	Node* node = new Node(S_init);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		//현 노드 앞에 새로운 노드로 삽입.
		if (a == 1) {
			cin >> s;
			Node* new_node = new Node(s);

			Insert_front(node, new_node);
		}

		//현 노드 뒤에 새로운 노드로 삽입.
		else if (a == 2) {
			cin >> s;
			Node* new_node = new Node(s);

			Insert_back(node, new_node);
		}

		//현 노드의 이전 노드가 존재한다면, cur를 이전 노드로 변경.
		else if (a == 3) {
			Pop_front(node);
		}

		//현 노드의 다음 노드가 존재한다면, cur를 다음 노드로 변경.
		else if (a == 4) {
			Pop_back(node);
		}

		if (nullptr == node->prev) {
			cout << "(Null) " << node->data << " " << node->next->data << "\n";
		}
		else if (nullptr == node->next) {
			cout << node->prev->data << " " << node->data << " " << "(Null) \n";
		}
		else if (nullptr == node->next && nullptr == node->prev) {
			cout << "(Null)" << " " << node->data << " " << "(Null) \n";
		}

		else {
			cout << node->prev->data << " " << node->data << " " << node->next->data << "\n";
		}
	}
}