//
// Created by yangtao on 20-6-17.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1005;
struct Node {
    int x, y;
    bool operator<(const Node &node) {
        return x < node.x;
    }
}node[N];
int n, k, cnt;
double x0 = -0x3f3f3f3f;
double circle(int x, int y) {
    return sqrt( x * x  + y * y);
}
int main() {
    while (1) {
        cin >> n >> k;
        cnt = 0;
        if (n == 0 && k == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &node[i].x, &node[i].y);
        }
        sort(node, node + n);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if(node[i].y > k) {
                flag = false;
                break;
            }
            double r = circle( x0 - node[i].x,  node[i].y);
            if (r > k) {
                x0 = sqrt(k * k - node[i].y * node[i].y);
                cnt++;
            }
        }

        if(flag)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}