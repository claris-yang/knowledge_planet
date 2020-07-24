//
// Created by yangtao on 19-10-12.
//

#include <iostream>
using namespace std;
int a[10005];
int main() {
    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for(int j = 10005; j >= 0; --j) {
            if(a[j]) a[j+t] = 1;
        }
    }
    for(int i = 0 ; i < 10005; ++i) {
        if(a[i]) cout << i << endl;
    }
    return 0;
}