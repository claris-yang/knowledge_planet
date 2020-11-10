//
// Created by yangtao on 20-10-23.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string, int>m;
const int N = 205;
int n;
char s[N];
int d[30] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1,  7, 7, 8, 8, 8, 9 ,9, 9, -1};
bool cmp(string a, string b) {
    return a < b;
}

string a[1000005];
int  main() {
    cin >> n;

    for(int i = 1; i <=n; i++) {
        scanf("%s", s);
        string t;
        int l = strlen(s);
        for(int j = 0; j < l ; j++) {
            if(s[j] == '-') {
                continue;
            } else if( s[j] >= '0' && s[j] <= '9') {
                t += s[j] ;
            } else {
                t += d[s[j]-'A'] + '0';
            }
        }
        if(m.find(t) != m.end()) {
            int num = m[t];
            m[t] = num + 1;
        } else {
            m[t] = 1;
        }
    }


    unordered_map<string, int>::iterator it = m.begin();
    int cnt = 0;
    for( ; it != m.end(); it++) {
        a[cnt++] = it->first;
    }

    sort(a, a + cnt, cmp);

    bool flag = false;
    for(int i = 0 ; i < cnt; i++) {
        if(m[a[i]] < 2) continue;
        for(int j = 0 ; j < 7; j++) {
            printf("%c", a[i][j]);
            if(j == 2) {
                printf("-");
            }
        }
        flag = true;
        printf(" %d\n", m[a[i]]);
    }

    if(!flag) cout << "No duplicates."<< endl;
    return 0;

}