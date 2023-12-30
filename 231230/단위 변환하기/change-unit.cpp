#include <iostream>

using namespace std;

int main() {
    cout << fixed;
    cout.precision(2);
    double mil = 160934.40;
    double ft = 30.48;

    cout << "2.80 mi = " << 2.80 * mil << "\n";
    cout << "128.40 ft = " << 128.40 * ft << "\n";



    return 0;
}