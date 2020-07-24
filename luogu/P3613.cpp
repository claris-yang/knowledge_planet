//
// Created by yangtao on 20-5-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
struct Node {
    int x, y, z;
};
vector<Node> a[N];
int n, q;
int opt;
int main() {
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        scanf("%d", &opt);
        if(opt == 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[x].push_back({x, y, z});
        } else if( opt == 2 ) {
            int x, y;
            scanf("%d%d", &x, &y);
            for(int i = a[x].size() - 1; i >= 0; i--) {
                if(a[x][i].y == y) {
                    printf("%d\n", a[x][i].z);
                    break;
                }
            }
        }
    }
    return 0;
}