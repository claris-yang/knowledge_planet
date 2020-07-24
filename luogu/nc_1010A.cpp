//
// Created by yangtao on 20-7-13.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
int trie[N][30], tail[N];
int tot = 1;

void insert(char *s) {
    int len = strlen(s), p = 1;
    //cout << s << endl;
    for(int i = 0 ;i < len ; i++) {
        if(!trie[p][s[i]-'a']) trie[p][s[i]-'a'] = ++tot;
        p = trie[p][s[i]-'a'];
    }
    tail[p]++;
    //cout << tail[p] << " " << p << endl;
}

int query(char *s) {
    int len = strlen(s), p = 1 ;
    //cout << s << endl;
    int cnt = 0 ;
    for(int i = 0 ;i < len ; i++) {
        p = trie[p][s[i]-'a'];
        //cout << p << endl;
        if(!p) return 0;
        if(tail[p]) cnt++;

    }
    return cnt;
}
int n, m;
int main() {
    cin >> n >> m;
    char s[N];
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    for(int i = 0 ;i < m; i++) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}