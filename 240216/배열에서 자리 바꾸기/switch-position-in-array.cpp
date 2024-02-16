#include <bits/stdc++.h>

#define MAX_N (250000)

using namespace std;

struct Node {
    int id;
    Node *prev, *next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N] = {};

// 두 노드를 연결해줍니다.
void connect(Node *s, Node *e) {
    if (nullptr != s)
        s->next = e;
    if (nullptr != e)
        e->prev = s;
}

// 부분 배열의 위치를 바꿔줍니다.
void swapSubarray(Node *a, Node *b, Node *c, Node *d) {
    // 연결된 이후 각각 a의 이전노드, b의 이후노드, c의 이전노드, d의 이후노드가
    // 무엇인지 기록합니다.
	Node *after_prevA = c->prev;
	Node *after_nextB = d->next;

	Node *after_prevC = a->prev;
	Node *after_nextD = b->next;

	// b와 c가 붙어있는 경우 예외 처리를 해줍니다.
	if (b->next == c) {
		after_prevA = d;
		after_nextD = a;
	}
	// d와 a가 붙어있는 경우 예외 처리를 해줍니다.
	if (d->next == a) {
		after_nextB = c;
		after_prevC = b;
	}

    // 각각의 노드를 연결합니다.
	connect(after_prevA, a);
	connect(b, after_nextB);

	connect(after_prevC, c);
	connect(d, after_nextD);
}

int main() {
    int n;
    cin >> n;

    // N개의 노드를 생성합니다.
    for (int i = 1; i <= n; i++)
        nodes[i] = new Node(i);

    // 1부터 N번 까지의 노드를 차례로 연결해줍니다.
    for (int i = 1; i < n; i++)
        connect(nodes[i], nodes[i + 1]);

    int q;
    cin >> q;

    // 연산을 진행합니다.
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        swapSubarray(nodes[a], nodes[b], nodes[c], nodes[d]);
    }

    // 연산이 끝나고 제일 앞에 있는 노드를 찾습니다.
    Node *cur = nodes[1];

    while (nullptr != cur->prev)
        cur = cur->prev;

    // 해당 노드부터 끝까지 출력을 합니다.
    while (nullptr != cur) {
        cout << cur->id << ' ';
        cur = cur->next;
    }
}