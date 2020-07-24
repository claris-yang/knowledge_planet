//
// Created by yangtao on 19-11-1.
//

#include <iostream>
using namespace std;
int n;
int a1 = 1, a2 = 1;
int main() {
    cin >> n;

    if(n >= 1)
        cout << '0' ;
    for(int i = 2; i <= n; i++) {
        if(i == a1 + a2) {
            cout << 0 ;
            a2 += a1;
            a1 = a2 - a1;
        } else {
            cout << 'o' ;
        }

    }
    return 0;
}
1 1 2 3 5 8 13 21