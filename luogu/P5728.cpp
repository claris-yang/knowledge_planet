//
// Created by yangtao on 20-4-29.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
struct Stu {
    int a, b, c;
    int total;
};

using namespace std;
const int N = 1005;
Stu a[N];
int n;
int tot;
int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        a[i].total = a[i].a + a[i].b + a[i].c;

    }
    int cnt = 0;
    for(int i = 0 ; i < n; i++) {

        for(int j = i + 1; j < n; j++) {
            bool flag = false;
            if( abs(a[i].a - a[j].a) > 5 || abs(a[i].b - a[j].b) > 5 || abs(a[i].c - a[j].c) > 5 ) {
                flag = true;
                continue;

            }
            if( abs(a[i].total - a[j].total) > 10  ) {
                flag = true;
                continue;
            }
            if(!flag) tot++;
        }
    }
    cout << tot << endl;
    return 0;
}