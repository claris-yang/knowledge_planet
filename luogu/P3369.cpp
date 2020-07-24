//
// Created by yangtao on 19-11-8.
//

#include <iostream>
const int N  = 1024;
using namespace std;
int to[N], ne[N], head[N];
int tot;
void add(int a, int b) {
    to[tot] = b, ne[tot] = head[a], head[a] = tot++;
}
int main() {
    return 0;
}