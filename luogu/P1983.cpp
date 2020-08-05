//
// Created by yangtao on 20-8-4.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int n, m, out[N], top, ans, a[N];
bool is[N], use[N];
int topu[N][N], temp[N];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int t;
        memset(is , 0, sizeof(is));
        cin >> t;
        for(int j = 1; j <= t; j++) {
            scanf("%d", &a[j]);
            is[a[j]] = true;
        }
        for(int j = a[1]; j <= a[t]; j++) {
            if(!is[j])
                for(int k = 1; k <= t; k++) {
                    if(!topu[j][a[k]] ) {
                        topu[j][a[k]] = 1, out[a[k]]++;
                }
            }
        }
    }


    do{
        top = 0 ;
        for(int i = 1; i <=n; i++) {
            if(!out[i] && !use[i]) {
                temp[++top] = i, use[i] = true;
            }
        }
        for(int i = 1; i <= top; i++) {
            for(int j = 1; j <=n; j++) {
                if(topu[temp[i]][j])
                    topu[temp[i]][j] = 0, out[j]--;
            }
        }
        ans++;
    } while (top);

    cout << --ans << endl;

    return 0;
}
