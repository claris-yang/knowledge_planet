//
// Created by yangtao on 20-4-28.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N  = 1005;
typedef long long ll;
ll f[N];
int n, m;


int n1[N], n2[N], res[N], tmp[N];
int l1 = 1, l2 = 1;
int ml;
void add() {

    ml = max(l1, l2) ;

    for(int i = 0 ; i < ml; i++) {
        res[i] += n1[i] + n2[i];
        if(res[i] >= 10) {
            res[i+1] = res[i] / 10;
            res[i] %= 10;
        }
    }

    if(res[ml] > 0) {
        ml++;
    }


    for(int i = 0; i < l2; i++) n1[i] = n2[i];
    for(int i = 0 ;i < ml; i++) n2[i] = res[i];
    l1 = l2, l2 = ml;

    for(int i = 0 ;i < ml; i++) tmp[i] = res[i];
    memset(res, 0, sizeof(res));
}
int main() {
    cin >> m >> n;
    if ( m <= 2 ) m = 2;

    n1[0] = 1, n2[0] = 1;
    for(int i = m; i < n; i++) {
        add();
    }

    for(int i = ml - 1; i >= 0; i--) cout << tmp[i];

    return 0;
}
