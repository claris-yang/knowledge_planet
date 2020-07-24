//
// Created by yangtao on 19-11-5.
//

#include <iostream>
using namespace std;
const int N = 1005;
int n, v;
int f[N], w[N], s[N];
int d[N];
int main() {
    cin >> n >> v;
    for(int i = 1; i <= n; i++) {
        cin >> f[i] >> w[i] >> s[i];
    }
    for(int i = 1;i <=n ; i++) {
        if(s[i] == 0) {
            for(int j = v; j >= f[i]; j--) {
                for(int k = 0; k * f[i] <= j; k++)
                    d[j] = max(d[j], d[j - f[j-1]] + k * w[i]);
            }
        } if (s[i] == -1) {
            for(int j = v; j >= f[i]; j--) {
                d[j] = max(d[j] , d[j - f[i-1]] + w[i]);
            }
        } else {
            for(int j = v; j >= f[i]; j--) {
                for(int k = 0; k <= s[i] && k * f[i] <= j; k ++)
                    d[j] = max(d[j], d[j - f[i-1]] + k * w[i]);
            }
        }
    }

    cout << d[v];
    return 0;
}