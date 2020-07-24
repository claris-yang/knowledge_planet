//
// Created by yangtao on 19-6-12.
//

#include <iostream>
using namespace std;
const int MAXVALUE = 2071024;
struct Node {
    int value;
    int left;
    int right;
}node[MAXVALUE];
int parent[MAXVALUE];

int maxvalue = -1 << 20;

void BuileTree(int i , int left, int right) {
    node[i].value = 0;
    node[i].left = left;
    node[i].right = right;
    if(left == right) {
        parent[left] = i;
        return 0;
    }
    BuileTree(i << 1, left, (int)floor((left + right) / 2.0));
    BuileTree((i << 1) + 1, (int)floor((left + right) / 2.0) + 1, right);
}

void UpdateTree(int i) {
    if(i == 1) return ;
    int fi = i / 2;
    int a = node[(fi<<1)].value;
    int b = node[(fi<<1) + 1].value;
    node[fi].value = max(a,b);
    UpdateTree(fi);
}

void Query(int i, int left, int right) {
    if(node[i].left == left && node[i].right == right) {
        maxvalue = max(maxvalue, node[i].value);
        return;
    }

    i = i << 1;
    if(left < node[i].right) {
        if( right < node[i].right) {
            Query(i, left, right);
        } else {
            Query(i, left, node[i].right);
        }
    }

    i++;

    if(right >= node[i].left){
        if(left >= node[i].left) {
            Query(i, left, right);
        } else {
            Query(i, node[i].left, r);
        }

    }
}

int main() {

    return 0;
}