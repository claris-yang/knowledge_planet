//
// Created by yangtao on 20-6-23.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int l;
    int t;
    bool operator<(const Node &node) const {
        return l > node.l;
    }
};
queue<Node> q1, q2;
vector<int> a;
int n, m, q, u, v, t;
double p1, p2;
int j;
int delta;
int main() {

    cin >> n >> m >> q > u >> v >> t;
    p1 = (double) u / v;
    p2 = 1 - p1;
    for(int i = 0 ;i < n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a, a + n);
    for(int i = 1; i <= m; i++) {

        int x = 0;
        if(j <= m) x = a[j] * delta;

        if( q1.size() > 0 ) {
            Node nd = q1.top();
            if ( x < nd.v * (i - nd.t) * q) {
                x = nd.v * (i - nd.t) * q ;
                q1.pop();
            }

        }
        if(q1.size() > 0 ) {
            Node nd = q2.top();
            if ( x < nd.v * (i - nd.t) * q) {
                x = nd.v * (i - nd.t) * q ;
                q2.pop();
            }
        }

        if( j <= m && x <= (double)a[j] * delta ) {
            j++;
        }

        int v1 = p1 * x;
        int v2 = p2 * x;
        q1.push({v1, i});
        q2.push({v2, i});

        delta += q;

        if(i % t == 0) {
            printf("%d ", x);
        }
    }

    cout << endl;
    while( j <= m && q1.size() && q2.siez() ) {

    }

    return 0;
}