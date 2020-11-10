//
// Created by yangtao on 20-10-15.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 100005;
int next[N], color[N], dfn[N], f[N], s[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &next[i]);
    }
    for(int j = 1; j <= n; j++) {
        for(int i = j, cnt = 0; ; i = next[i], cnt++) {
            if(!color[i]) {
                color[i] = j;
                dfn[i] = cnt;
            } else if (color[i] == j) {
                f[j] = cnt - dfn[i];
                s[j] = dfn[i];
                cout << cnt << endl;
                break;
            } else {
                f[j] = f[color[i]];
                s[j] = cnt + max(s[color[i]] - dfn[i], 0);
                cout << s[j] + f[j] << endl;
                break;
            }
        }
    }
    return 0;
}