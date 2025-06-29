#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin >> n;
    getchar(); // Ignore the newline character after reading n
    while(n --) {
        string path;
        getline(cin, path);
        cout << path << endl;;
    }
    
}