//
// Created by yangtao on 20-4-10.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 25;
int a[N];
int n, r;
void dfs(int b, int val) {
    if(b == r) {
        for(int i = 0; i < r; i++) {
            printf("%3d", a[i]);
        }
        printf("\n");
        return ;

    }
    for(int i = val + 1; i <= n; i++) {
        a[b] = i;
        dfs( b + 1, i);
    }
}
int main() {
    cin >> n >> r;
    dfs(0, 0 );
    return 0;
}