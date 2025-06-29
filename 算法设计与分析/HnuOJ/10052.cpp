#include <iostream>
#include <math.h>
 
using namespace std;
 
int main()
{
    int s;
 
    while(cin >> s) {
        for(int i=sqrt(s); ;i++) {
            int sn = (i + 1) * i / 2;
            if(sn >= s && (sn - s) % 2 == 0) {
                cout << i << endl;
                break;
            }
        }
    }
 
    return 0;
}