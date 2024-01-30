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
//i, j j 번 노드를 i 번 노드 앞에 삽입.
void Insert_Front(Node* u_1, Node* u_2) {
	u_2->prev = u_1->prev;
	u_2->next = u_1;

	if (nullptr != u_2->prev) {
		u_2->prev->next = u_2;
	}
	if (nullptr != u_2->next) {
		u_2->next->prev = u_2;
	}
}

// 해당 u 삭제. 앞 뒤 연결.
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

//i, j j 번 노드를 i 번 노드 뒤에 삽입.
void Insert_Back(Node* u_1, Node* u_2) {
	u_2->prev = u_1;
	u_2->next = u_1->next;

	if (nullptr != u_2->prev) {
		u_2->prev->next = u_2;
	}
	if (nullptr != u_2->next) {
		u_2->next->prev = u_2;
	}
}

void Print_Nodes(Node* n) {
	string s = "0";

	if (n->prev == nullptr) cout << s << " ";
	else cout << n->prev->data << " ";

	if (n->next == nullptr) cout << s << "\n";
	else cout << n->next->data << "\n";
}

int main() {
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		nodes[i] = new Node(i);

		//cout << nodes[i]->data << " ";
	}
	//cout << "\n";

	for (int t = 0; t < Q; t++) {
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
			
			Insert_Front(nodes[i], nodes[j]);
		}

		else if (a == 3) {
			int i, j;
			cin >> i >> j;

			Insert_Back(nodes[i], nodes[j]);
		}
		else if (a == 4) {
			int num;
			cin >> num;

			Print_Nodes(nodes[num]);
		}
	}
	string s = "0";

	for (int i = 1; i <= N; i++) {
		Node* cur = nodes[i];

		if (cur->next == nullptr) cout << s << " ";
		else cout << cur->next->data << " ";

	}

	//for (auto i = nodes.begin(); i != nodes.end(); i++) {
	//	int n = i->first;
	//	Node* cur = i->second;
	//	if (cur->next == nullptr) {
	//		cout << s << " ";
	//	}
	//	else {
	//		cout << cur->next->data << " ";
	//	}
	//}

}