//
// Created by yangtao on 20-8-1.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];
int n, ans1, ans2;
int f[N];
int main() {
    while( EOF != scanf("%d", &a[++n]) ) ;

        for(int i = 1; i < n; i++) {
            f[i] = 1;
            for(int j = 1; j < i ; j++) {
                if(a[i] <= a[j] ) f[i] = max(f[i], f[j] + 1);
            }
            ans1 = max(ans1, f[i]);
        }

    memset(f, 0, sizeof(f));
        for(int i = 1; i < n; i++ ) {
            f[i] = 1;
            for(int j = 1; j < i ; j++) {
                if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
            }
            ans2 = max(ans2, f[i]);
        }

    cout << ans1 << endl << ans2 << endl;

    return 0;
}