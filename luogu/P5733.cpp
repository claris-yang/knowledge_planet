//
// Created by yangtao on 20-4-30.
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
char c[N];
int main() {
    cin >> c;
    for(int i = 0 ;i < strlen(c) ; i++) {
        if(c[i] >= 'a' && c[i] <= 'z') {
            c[i] = c[i] - ('a' - 'A');
        }
    }
    cout << c << endl;
    return 0;
}
