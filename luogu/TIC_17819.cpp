//
// Created by yangtao on 19-9-20.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    int a[2005];
    int b1 = 0, b2 = 0;
    int m = 0;
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) {
            b2++;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        if(a[i] % 2 != 0) {
            b1++;
        } else {
            b2--;
        }
        m = max(b1+b2, m);
    }
    cout << m << endl;
    return 0;
}