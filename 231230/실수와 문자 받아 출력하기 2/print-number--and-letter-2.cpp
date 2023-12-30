#include <iostream>

using namespace std;

int main() {
	cout << fixed;
	cout.precision(2);

	char s;
	double x, y;
	cin >> s >> x >> y;

	cout << y << "\n" << x << "\n" << s;

}