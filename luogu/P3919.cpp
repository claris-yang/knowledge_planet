//
// Created by yangtao on 20-6-29.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
struct Node {
    int l, r, val;
}hjt[N * 40];
int a[N], root[N];
int n,m, cnt;

inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}

void build(int l, int r, int &now) {
    now = ++cnt;
    if(l == r) {
        hjt[now].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, hjt[now].l);
    build(mid+1, r, hjt[now].r);
}

void modify(int l, int r, int ver, int &now, int pos, int val)  {
    now = ++cnt;
    hjt[now] = hjt[ver];
    if(l == r) {
        hjt[now].val = val;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) {
        modify(l, mid, hjt[ver].l, hjt[now].l, pos, val);
    } else {
        modify(mid + 1, r, hjt[ver].r, hjt[now].r, pos, val);
    }
}
int query(int l, int r, int now, int pos ) {
    if(l == r) {
        //cout << hjt[now].val << endl;
        return hjt[now].val;
    }
    int mid = l + r >> 1;
    if(pos <= mid) {
        return query(l, mid, hjt[now].l, pos);
    } else {
        return query(mid+1, r, hjt[now].r, pos);
    }
}
int main() {
    cin >>  n >> m;
    for(int i = 1; i <=n; i++) scanf("%d", &a[i]);
    build(1, n, root[0]);
    for(int i = 1 ;i <= m; i++) {
        int ver, opt;
        ver =read(), opt = read();
        if( opt == 1) {
            int pos, val;
            pos = read(), val = read();
            modify(1, n, root[ver], root[i], pos, val);
        } else {
            int pos;
            pos = read();
            printf("%d\n", query(1, n, root[ver], pos));
            root[i] = root[ver];
        }
    }
    return 0;
}