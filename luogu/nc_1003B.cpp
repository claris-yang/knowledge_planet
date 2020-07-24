//
// Created by yangtao on 20-6-17.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 50005;

struct Node {
    int s, t, no;
    bool operator<(const Node &node) const {
        return s < node.s;
    }
};

Node node[N];

int n, cnt;

int a[N], b[N];

int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        scanf("%d%d", &node[i].s, &node[i].t);
        node[i].no = i + 1;
    }
    sort(node, node+n);

    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(int j = 1;j <= cnt; j++) {
            if( node[a[j]].t < node[i].s) {
                a[j] = i;
                b[node[i].no] = j;
                flag = true;
                break;
            }
        }
        if(!flag) {
            a[++cnt] = i;
            b[node[i].no] = cnt;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++) {
        printf("%d\n", b[i]);
    }

    return 0;
}