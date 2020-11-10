//
// Created by yangtao on 20-9-21.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
struct Node {
    long long ks, t;
    bool operator<(const Node &node ) const {
        return ks > node.ks;
    }
}a[N];
long long  n, k, cnt[N], num = 1, f[N];
int main () {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i].ks >> a[i].t;
        cnt[a[i].ks]++;
    }
    sort(a + 1, a + k + 1) ;
    for(int i = n; i >= 1; i--) {
        if(!cnt[i]) {
            f[i] = f[i+1] + 1;
        } else {
            for(int j = 1; j <= cnt[i]; j++) {
                if(f[i] < f[i + a[num].t]) {
                    f[i] = f[i + a[num].t];
                }
                num++;
            }
        }
    }
    cout << f[1];
    return 0;

}
