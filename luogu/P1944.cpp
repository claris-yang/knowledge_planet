//
// Created by yangtao on 20-7-8.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1000005;
int vis[N];
char s[N];
pair<char, int> ss[N];
int top;
int main( ) {
    scanf("%s", s+1);

    int la = strlen(s + 1);
    for(int i = 1; i <= la; i++) {

        if(ss[top].first == '(' && s[i] == ')' || ss[top].first == '[' && s[i] == ']') {
            pair<char, int> t = ss[top--];
            vis[i] = vis[t.second] = 1;
        } else {
            ss[++top] = make_pair(s[i], i);
        }

    }

    int len = 0;
    int res = 0;
    int start = 1;
    int l = 1, r = 1;
    for(int i = 1; i <= la; i++) {
        if(!vis[i]) {
            res = 0; l = i + 1;
        } else {
            res++;
            if( len < res) {
                len = res;
                start = l;
                r = i;
            }
        }
    }
    for(int i = start; i <= r; i++) {
       putchar(s[i]);
    }

    return 0;
}