#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < 5; i++) {
		double a;
        cin >> a;
		cout << round(a*1000)/1000 << "\n";
	}
}