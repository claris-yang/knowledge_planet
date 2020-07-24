//
// Created by yangtao on 19-11-12.
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 205;
int d[N][N];
int m[N][N];
int f[N];
int n,ans1 = 1e8, ans2;
int main() {

    cin >> n;

    //memset(m, 0x3f, sizeof(m));
    for(int i = 1; i <= n; i++ ) {
       cin >> f[i];
       f[i+n] = f[i];
    }

    for(int i = 2; i <= 2 * n; i++)
        f[i] += f[i-1];


    for(int i = 1; i <= 2 * n; i++)
        for(int j = i + 1; j <= 2 * n; j++)
            m[j][i] = 1e8;


    //for(int i = 0 ; i <= n * 2; i++) m[i][i] = 0;
    for(int l = 1; l < n; l++) {
        for(int i = 1; i + l <= n * 2; i++) {
            int j = i + l;
            for(int k = i ; k < j; k++) {
                d[i][j] = max(d[i][j], d[i][k] + d[k+1][j] + f[j] - f[i-1] );
                m[i][j] = max(m[i][j], m[i][k] + m[k+1][j] + f[j] - f[i-1]);
                //cout << m[i][j] << endl;
            }
        }
    }

    for(int i = 1; i <=n; i++) {
        ans1 = min(ans1, m[i][i+n-1]);
        ans2 = max(ans2, d[i][i+n-1]);
    }

    cout << ans1 << endl << ans2 << endl;
    return 0;
}