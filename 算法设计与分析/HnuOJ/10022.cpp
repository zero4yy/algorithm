#include<iostream>
using namespace std;
int main() {
    char ch;
    string s;
    int m, n = 0;
    while (cin >> s) {
        if (s == "#")
            break;
        else if (s == "0") {
            cout << n << endl;
            n = 0;
        } else {
            cin >> s >> m >> ch;
            if (ch == 'F')
                n += 2 * m;
            else if (ch == 'B')
                n += m + (m + 1) / 2; //四舍五入
            else if (ch == 'Y' && m <= 500)
                n += 500;
            else
                n += m;
        }
    }
    return 0;
}