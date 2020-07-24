//
// Created by yangtao on 20-4-17.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 105;
int f[N][N];
struct Book {
    int x, y;
    bool operator<(const Book & b) const {
        return x < b.x;
    }
};
Book a[N];
int n, m;
int main() {
    cin >> n >> m;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <=n ; i++) {
        cin >> a[i].x >> a[i].y ;
        //f[i][0] = min(f[i][i], a[i].y);
        f[i][0] = 0;
    }
    sort(a + 1, a + n + 1);
    f[1][0] = 0;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= n - m; j++) {
            for(int k =  1 ; k < i; k++)
                f[i][j] = min(f[i][j], f[k][j-1] + abs(a[i].y - a[k].y));

        }
    }

    int res = 0x3f3f3f3f;
    for(int i = m; i <= n; i++)
        res = min(res, f[i][m]);

    cout << res << endl;

    return 0;
}
