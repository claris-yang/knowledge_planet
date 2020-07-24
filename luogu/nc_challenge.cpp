//
// Created by yangtao on 20-6-2.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50005;
int e[N], ne[N], h[N], w[N], t[N];
int n, idx, root, dis;
void add(int x, int y, int z) {
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

void dfs(int x, int dep){
    dis = max(dis, dep);
    for(int i = h[x]; ~i; i = ne[i]) {
        dfs(e[i], dep + w[i]);
    }
}
int main() {
    cin >> n;
    memset(h, -1, sizeof(h));
    for(int i = 1 ;i < n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(y, x, z);
        t[x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(t[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root, 0);

    cout << dis << endl;

    return 0;
}