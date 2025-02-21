#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
    node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

struct list {
    node* head;
    node* tail;
};

vector<node*> narr;
vector<list> low;
vector<int> pos;
int n, m, q;

void connect(node* a, node* b) {
    if (a != nullptr) a->next = b;
    if (b != nullptr) b->prev = a;
}

void pr() {
    for (int i = 1; i <= m; i++) {
        node* ptr = low[i].head;
        if (ptr == nullptr) {
            cout << -1 << '\n';
            continue;
        }
        while (ptr != nullptr) {  // tail->next로 순회 종료하지 않고 nullptr로 처리
            cout << ptr->data << ' ';
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;

    narr = vector<node*>(n + 1);
    pos = vector<int>(n + 1);
    low = vector<list>(m + 1);

    for (int i = 1; i <= n; i++) {
        narr[i] = new node(i);
    }

    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        if (s == -1) continue;
        vector<int> arr(s, 0);
        for (int j = 0; j < s; j++) {
            cin >> arr[j];
            pos[arr[j]] = i;
        }
        low[i].head = narr[arr[0]];
        low[i].tail = narr[arr[s - 1]];

        for (int j = 0; j < s - 1; j++) {
            connect(narr[arr[j]], narr[arr[j + 1]]);
        }
    }

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        if (k == 1) {  // 이동 (a를 b 앞으로 이동)
            int a, b;
            cin >> a >> b;
            int p = pos[a];

            if (low[p].head == narr[a] && low[p].tail == narr[a]) {
                low[p].head = nullptr;
                low[p].tail = nullptr;
            } else if (low[p].head == narr[a]) {
                low[p].head = narr[a]->next;
                if (low[p].head) low[p].head->prev = nullptr;
            } else if (low[p].tail == narr[a]) {
                low[p].tail = narr[a]->prev;
                if (low[p].tail) low[p].tail->next = nullptr;
            } else {
                node* ap = narr[a]->prev;
                node* an = narr[a]->next;
                connect(ap, an);
            }

            int pb = pos[b];
            if (low[pb].head == narr[b]) {
                low[pb].head = narr[a];
            }

            node* bp = narr[b]->prev;
            connect(bp, narr[a]);
            connect(narr[a], narr[b]);

            pos[a] = pb;
        }

        else if (k == 2) {  // a를 리스트에서 삭제
            int a;
            cin >> a;
            int p = pos[a];

            if (low[p].head == narr[a]) {
                low[p].head = narr[a]->next;
                if (low[p].head) low[p].head->prev = nullptr;
            } else if (low[p].tail == narr[a]) {
                low[p].tail = narr[a]->prev;
                if (low[p].tail) low[p].tail->next = nullptr;
            } else {
                node* pNode = narr[a]->prev;
                node* nNode = narr[a]->next;
                connect(pNode, nNode);
            }

            delete narr[a];  // 메모리 해제
            narr[a] = nullptr;
        }

        else if (k == 3) {  // [a, b] 구간을 c 앞에 붙이기
            int a, b, c;
            cin >> a >> b >> c;
            int p = pos[a];

            if (low[p].head == narr[a] && low[p].tail == narr[b]) {
                low[p].head = nullptr;
                low[p].tail = nullptr;
            } else if (low[p].head == narr[a]) {
                low[p].head = narr[b]->next;
                if (low[p].head) low[p].head->prev = nullptr;
            } else if (low[p].tail == narr[b]) {
                low[p].tail = narr[a]->prev;
                if (low[p].tail) low[p].tail->next = nullptr;
            } else {
                node* ap = narr[a]->prev;
                node* bn = narr[b]->next;
                connect(ap, bn);
            }

            int pc = pos[c];
            if (low[pc].head == narr[c]) {
                low[pc].head = narr[a];
            }

            node* cp = narr[c]->prev;
            connect(cp, narr[a]);
            connect(narr[b], narr[c]);

            node* ptr = narr[a];
            while (ptr != nullptr && ptr != narr[b]->next) {  // nullptr 체크 추가
                pos[ptr->data] = pc;
                ptr = ptr->next;
            }
        }
    }

    pr();
}
