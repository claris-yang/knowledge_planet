//
// Created by yangtao on 20-5-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1205;
int f[N];
int a[N];
int d[4];
int total;
int res;
int maxn;
int main() {

    for(int i =  0; i < 4; i++) {
        scanf("%d", &d[i]);
    }

    for(int k = 0 ; k < 4; k++) {

        maxn = 0;
        memset(f, 0, sizeof(f));
        total = 0;

        for(int i = 1; i <= d[k];i++) {
            scanf("%d", &a[i]);
            total += a[i];
        }

        for(int i = 1; i <= d[k]; i++) {
            for(int j = total / 2 ; j >= a[i]; j--) {
                f[j] = max(f[j], f[j-a[i]] + a[i]);
                maxn = max(maxn, f[j]);
            }
        }

        res += max(maxn, total - maxn);
    }
    cout << res << endl;
    return 0;
}