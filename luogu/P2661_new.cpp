//
// Created by yangtao on 19-12-16.
//

#include <cstdio>
using namespace std;
const int N = 200005;
int fa[N], a[N], d[N];
int n;
int min;
void merge(int i, int j) {
    int fx = find(i);
    int fy = find(y);
    if(fx != fy) {
        fa[i] = fy;
    }

}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        scanf("%d", &a);
    }

    return 0;
}