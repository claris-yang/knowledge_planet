//
// Created by yangtao on 20-8-22.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int x[N], y[N], a[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i =  1; i <= n; i++) {
        x[i] = 1;
        for(int j = 1; j < i ; j++) {
            if( a[i] > a[j]) {
                x[i] = max(x[i], x[j] + 1);
            }
        }
    }

    for(int i = n; i >=1; i--) {
        y[i] = 1;
        for(int j = n ; j > i; j--) {
            if( a[i] > a[j]) {
                y[i] = max(y[i], y[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, x[i] + y[i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}