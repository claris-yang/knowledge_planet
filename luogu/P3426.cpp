//
// Created by yangtao on 20-7-27.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;
int next[N], f[N], h[N];
char a[N];
int n;
int main() {
    cin >> a + 1;
    n = strlen(a + 1);
    for(int i = 2, j = 0; i <= n; i++) {
        while(j && a[j+ 1] != a[i]) j = next[j];
        if(a[j+1] == a[i]) j++;
        next[i] = j;
    }
    f[1] = 1;
    for(int i= 2; i <= n; i++) {
        f[i] = i;
        if(h[f[next[i]]] >= i - next[i]) f[i] = f[next[i]];
        h[f[i]] = i;
    }
    cout << f[n];
    return 0;
}
