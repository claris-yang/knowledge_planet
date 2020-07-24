//
// Created by yangtao on 20-5-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
int order[N], closen[N];
int n;
void dfs(int x) {
    if (x == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", order[i] );
        }
        cout << endl;
        return ;
    }

    for(int i = 1; i <= n; i++) {
        if( closen[i] ) continue;
        closen[i] = 1;
        order[x] = i;
        dfs(x + 1);
        order[x] = 0;
        closen[i] = 0;
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}
