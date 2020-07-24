//
// Created by yangtao on 19-11-12.
//

#include <iostream>
using namespace std;
const int N = 205;
int d[N][N];
int a[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }

    int ans = 0;
    for(int l = 1; l <= n ; l++) {
        for(int i = 1; i + l <= 2 * n; i++) {
            int j = i + l;
            for(int k = i+1; k < j; k++) {
                d[i][j] = max(d[i][j] , d[i][k] + d[k][j]+ a[i] * a[k] * a[j]);
            }
        }
    }

    for(int i = 1; i <=  n ; i++) {
        ans = max(ans, d[i][i+n]);
    }

    cout << ans << endl;


    return 0;
}