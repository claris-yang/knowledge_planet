//
// Created by yangtao on 20-10-27.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int N= 1005;
int n, a[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            int t;
            scanf("%d", &t);
            if(t) cnt++;
            a[j] = t;
        }
        cout << cnt << " ";
        for(int j = 1; j <= n; j++) {
            if(a[j]) cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
