//
// Created by yangtao on 20-6-16.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3e6 + 5;
int s[N];
int a[N],f[N];
int n,top;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1 ; i <= n; i++) {
        while (top > 0 && a[s[top]] < a[i]) {
            f[s[top--]] = i;
        }
        s[++top] = i;
    }

    for(int i = 1;  i<=n; i++) {
        printf("%d " , f[i]);
    }

    return 0;
}
