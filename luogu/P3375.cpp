//
// Created by yangtao on 20-7-20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
char a[N], b[N];
int next[N], f[N];
int n, m;
int main() {
    cin >> b + 1 >> a + 1;
    n = strlen(a + 1);
    m = strlen(b + 1);
    next[1] = 0;
    for(int i = 2, j = 0; i <= n; i++) {
        while( j > 0 && a[j+1] != a[i] ) j = next[j];
        if(a[j+1] == a[i] ) j++;
        next[i] = j;
    }
    for(int i = 1, j = 0; i <= m; i++) {
        while(j > 0 && a[j+1] != b[i] ) j = next[j];
        if(b[i] == a[j+1]) j++;
        f[i] = j;
        if(f[i] == n) {
            printf("%d\n", i - n + 1);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << next[i] << " " ;
    }
    return 0;
}