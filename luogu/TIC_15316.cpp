//
// Created by yangtao on 19-9-20.
//

#include <iostream>
using namespace std;
bool div2(int a) {
    if(a == 0) return false;
    while(a % 2 == 0) {
        a /= 2;
    }
    return a==1 || a==-1;
}
bool div1(int a, int b) {
    if(a < b) {
        int t = a;
        a = b;
        b = t;
    }
    if(a % b != 0) {
        return false;
    }

    return div2(a / b);
}
int main() {
    int n;
    int a[105];
    cin >> n;
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n ; i++) {
        if(!div1(a[i], a[i-1])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
