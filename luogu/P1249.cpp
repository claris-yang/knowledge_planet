//
// Created by yangtao on 20-4-3.
//

#include <iostream>
using namespace std;
const int N = 40005;

int a[N], b[N];
char s1[N], s2[N];

int res = 1;
int mm = 0;


void dfs(int n ) {
    if(n <= 0) {
        return ;
    }
    for(int i = 2; i * i <= n ; i++) {
        res *= i;
        dfs(n - i);
    }
};
int main() {
    int n ;
    cin >> n;
    dfs(n);
    cout << res << endl;
    return 0;
}