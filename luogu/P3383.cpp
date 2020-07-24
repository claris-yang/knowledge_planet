//
// Created by yangtao on 19-8-12.
//

#include <iostream>
#include <cstdio>
using namespace std;
bool a[10000005];
bool ans[100005];
int n, m;
void getPrime() {
    for( int i = 2; i <= n; i++) {
        a[i] = true;
    }
    for(int i = 2; i * i <= n; i++) {
        if(!a[i]) {
            continue;
        }
        for(int j = i * i; j <=n; j+=i) {
            a[j] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    getPrime();
    for(int i = 0 ;i < m ; i++) {
         int num;
         scanf("%d", &num);
         ans[i] = a[num];
    }
    for(int i = 0 ;i < m; i++) {
        if(ans[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}