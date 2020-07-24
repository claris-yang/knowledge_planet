//
// Created by yangtao on 19-11-6.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, q;
int book[1005], need[1005];
int len[1005];
int mm;

int pow(int a, int b) {
    int res = 1;
    for(int i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        scanf("%d", &book[i]);
    }
    for(int i = 0 ;i < q; i++) {
        scanf("%d%d", &len[i], &need[i]);
    }

    sort(book, book+n);
    for(int i = 0 ;i < q; i++) {
        int j = 0;
        for(j = 0; j < n ; j++) {
            if (book[j] % pow(10, len[i]) == need[i]) break;
        }
        if(j < n) {
            printf("%d\n", book[j]);
        } else {
            puts("-1");
        }
    }

    return 0;
}