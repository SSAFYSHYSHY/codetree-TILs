#include <iostream>

#define MAX_N 250000
#define MAX_K 100

using namespace std;

// 연결 리스트의 노드
struct Node {
	// 책의 번호
	int data;

	// 이전 노드와 다음 노드
	Node *prev, *next;

	// 번호가 data인 단일 노드를 만드는 생성자
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// 노드를 번호순으로 배열로 관리
Node *nodes[MAX_N + 1];

// 각 연결 리스트의 head와 tail을 배열로 관리
Node *heads[MAX_K + 1], *tails[MAX_K + 1];

// i번 연결 리스트가 비어있는지 여부
bool empty(int i) {
	return nullptr == heads[i];
}

// 노드 u와 v를 서로 연결
void connect(Node *u, Node *v) {
	u->next = v;
	v->prev = u;
}

// i번 연결 리스트의 head를 삭제한 후 반환
Node* pop_front(int i) {
	Node *ret = heads[i];

	if (nullptr != ret) {
		// head를 뒤로 하나 이동
		heads[i] = ret->next;

		// 노드 ret를 단일 노드로 만듦
		ret->next = nullptr;

		if (nullptr != heads[i])
			// 연결 리스트가 비어있지 않다면, head의 이전 노드를 Null로 설정
			heads[i]->prev = nullptr;
		else
			// 연결 리스트가 비어있다면, tail도 Null로 설정
			tails[i] = nullptr;
	}

	return ret;
}

// i번 연결 리스트의 tail을 삭제한 후 반환
Node* pop_back(int i) {
	Node *ret = tails[i];

	if (nullptr != ret) {
		// tail을 앞으로 하나 이동
		tails[i] = ret->prev;

		// 노드 ret를 단일 노드로 만듦
		ret->prev = nullptr;

		if (nullptr != tails[i])
			// 연결 리스트가 비어있지 않다면, tail의 다음 노드를 Null로 설정
			tails[i]->next = nullptr;
		else
			// 연결 리스트가 비어있다면, head도 Null로 설정
			heads[i] = nullptr;
	}

	return ret;
}

// i번 연결 리스트의 맨 앞에 단일 노드 singleton을 삽입
void push_front(int i, Node *singleton) {
	if (nullptr == heads[i]) {
		// 연결 리스트가 비어있다면, head와 tail은 모두 singleton
		heads[i] = tails[i] = singleton;
	} else {
		// 연결 리스트가 비어있지 않다면, 기존의 head 앞에 singleton을 삽입
		connect(singleton, heads[i]);
		heads[i] = singleton;
	}
}

// i번 연결 리스트의 맨 뒤에 단일 노드 singleton을 삽입
void push_back(int i, Node *singleton) {
	if (nullptr == tails[i]) {
		// 연결 리스트가 비어있다면, head와 tail은 모두 singleton
		heads[i] = tails[i] = singleton;
	} else {
		// 연결 리스트가 비어있지 않다면, 기존의 tail 뒤에 singleton을 삽입
		connect(tails[i], singleton);
		tails[i] = singleton;
	}
}

// i번 연결 리스트를 j번 연결 리스트 앞에 삽입
void move_all_front(int i, int j) {
	// 무의미한 연산에 대한 예외처리
	if (i == j || empty(i))
		return;

	if (empty(j)) {
		// j번 연결 리스트가 비어있다면, head와 tail은 i번의 것과 동일
		heads[j] = heads[i];
		tails[j] = tails[i];
	} else {
		// j번 연결 리스트가 비어있지 않다면
		// i번의 tail과 j번의 head를 연결하고
		// j번의 head는 i번의 head가 됨
		connect(tails[i], heads[j]);
		heads[j] = heads[i];
	}

	// 이제, i번 연결 리스트는 비어있음
	heads[i] = tails[i] = nullptr;
}

// i번 연결 리스트를 j번 연결 리스트 뒤에 삽입
void move_all_back(int i, int j) {
	// 무의미한 연산에 대한 예외처리
	if (i == j || empty(i))
		return;

	if (empty(j)) {
		// j번 연결 리스트가 비어있다면, head와 tail은 i번의 것과 동일
		heads[j] = heads[i];
		tails[j] = tails[i];
	} else {
		// j번 연결 리스트가 비어있지 않다면
		// j번의 tail과 i번의 head를 연결하고
		// j번의 tail는 i번의 tail이 됨
		connect(tails[j], heads[i]);
		tails[j] = tails[i];
	}

	// 이제, i번 연결 리스트는 비어있음
	heads[i] = tails[i] = nullptr;
}

int main() {
	int n, k;
	cin >> n >> k;

	// n 개의 단일 노드 생성
	for (int i = 1; i <= n; i++)
		nodes[i] = new Node(i);

	// n 개의 노드를 일렬로 연결
	for (int i = 1; i < n; i++)
		connect(nodes[i], nodes[i+1]);

	// k 개의 연결 리스트 초기화
	for (int i = 1; i <= k; i++)
		heads[i] = tails[i] = nullptr;

	// 초기에 1번 연결 리스트는 n 개의 노드를 모두 가짐
	heads[1] = nodes[1];
	tails[1] = nodes[n];

	int q;
	cin >> q;

	for (int t = 0; t < q; t++) {
		int type, i, j;
		cin >> type >> i >> j;

		if (1 == type) {
			// i번 연결 리스트에서 맨 앞 노드를 가져옴
			Node *node = pop_front(i);

			// 그 노드를 j번 연결 리스트 맨 뒤에 삽입
			if (nullptr != node)
				push_back(j, node);
		} else if (2 == type) {
			// i번 연결 리스트에서 맨 뒤 노드를 가져옴
			Node *node = pop_back(i);

			// 그 노드를 j번 연결 리스트 맨 앞에 삽입
			if (nullptr != node)
				push_front(j, node);
		} else if (3 == type) {
			// i번 연결 리스트를 j번 연결 리스트의 맨 앞에 삽입
			move_all_front(i, j);
		} else if (4 == type) {
			// i번 연결 리스트를 j번 연결 리스트의 맨 뒤에 삽입
			move_all_back(i, j);
		}
	}

	// 각 연결 리스트를 순회
	for (int i = 1; i <= k; i++) {
		int cnt = 0;

		// i번 연결 리스트를 순회하여 노드의 수를 셈
		Node *cur = heads[i];
		while (nullptr != cur) {
			cnt++;
			cur = cur->next;
		}

		cout << cnt;

		// i번 연결 리스트를 순회하면서 각 노드의 값을 출력
		cur = heads[i];
		while (nullptr != cur) {
			cout << ' ' << cur->data;
			cur = cur->next;
		}
		
		cout << '\n';
	}

	// 생성한 노드를 모두 메모리에서 해제
	// 필수는 아니지만 권장하는 작업입니다.
	for (int i = 1; i <= n; i++) {
		delete nodes[i];
		nodes[i] = nullptr;
	}

	return 0;
}