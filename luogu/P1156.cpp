//
// Created by yangtao on 19-11-13.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105;
int d, g;
int f[1005];
int t[N], l[N], h[N];
struct Node {
    int t, l, h;
    bool operator<(const Node & n) const {
        return t < n.t;
    }
} nodes[N];
int main() {
    cin >> d >> g;

    memset(f, -1, sizeof(f));

    for( int i = 0; i < g; i++) {
        cin >> nodes[i].t >> nodes[i].l >> nodes[i].h;
    }

    sort(nodes, nodes + g);

    int i ;
    f[0] = 10;
    int ans = 10;
    bool over = false;
    for(i = 0 ; i < g; i++) {

        over = true;
        for(int j = d; j >= 0; j--) {

            if( j >= nodes[i].h) {
                if(f[j] == -1) {
                    if( f[j - nodes[i].h] >= nodes[i].t ) {
                        f[j] = f[j-nodes[i].h];
                        over = false;
                    }
                } else {
                    f[j] += nodes[i].l;
                    if(j + nodes[i].h >= d) {
                        cout << nodes[i].t << endl;
                        return 0;
                    }
                    over = false;
                }
            } else {
                if( f[i] != -1) {
                    f[i] += nodes[i].l;
                    over = false;
                }
            }

        }
        ans = nodes[i].t;
        for(int k = 0; k <= d; k++)
            cout << f[k] << ' ';
        cout << endl << endl;

        if(over) break;
    }

    cout <<  ans << endl;
    return 0;
}