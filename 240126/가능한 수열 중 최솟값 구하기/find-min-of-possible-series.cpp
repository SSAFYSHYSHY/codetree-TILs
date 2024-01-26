#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
bool flag = false;

//하나라도 일치하지 않으면 그냥 반환.
bool Calc2(int s1, int e1, int s2, int e2)  {
    for(int i = 0; i <= e1 - s1 ; i++) {
        if(v[s1 + i] != v[s2 + i] ) {
            return false;
        }
    }

    return true;
}

bool Same() {
    int len = 1;
    while(1) {
        int e1 = v.size() - 1, s1 = e1 - len + 1;
        int e2 = s1 - 1, s2 = e2 - len + 1;

        if(s2 < 0) break;

        if(Calc2(s1, e1, s2, e2)) {
            return false;
        }

        len++;
    }

    return true;
}

void Calc(int now) {
	if (now == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
        exit(0);
	}

	for (int i = 4; i <= 6; i++) {
		v.push_back(i);
		if (Same()) {
			Calc(now + 1);
		}
		v.pop_back();
	}
}

int main() {
	cin >> n;
	
	Calc(0);


}