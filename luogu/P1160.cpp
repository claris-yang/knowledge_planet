//
// Created by yangtao on 20-5-29.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct Node {
    Node *left, *right;
    int no;
};

map<int, Node*> s;
int n,m;
Node *h , *p;
int main() {
    cin >> n;
    h = new Node;
    Node *t = new Node;
    t->no = 1;
    h->right = t;
    t->left = h;
    s[1] = t;
    for(int i = 2; i <= n; i++) {
        Node *node = new Node;
        node->no = i;
        int k, q;
        scanf("%d%d", &k, &q);
        p = h->right;

        s[i] = node;
        p = s[k];

        if(q == 0) {
            node->left = p->left;
            node->right = p;
            p->left->right = node;
            p->left = node;
        } else {
            node->right = p->right;
            node->left = p;
            p->right = node;
            if(node->right)
                node->right->left = node;
        }

    }
    cin >> m;
    for(int i = 0 ; i < m; i++) {
        int q;
        scanf("%d", &q);
        if(s.find(q) == s.end()) continue;
        p = s[q];
        s.erase(q);
        p->left->right = p->right;
        if(p->right) {
            p->right->left = p->left;
        }
    }
    p = h->right;
    while(p) {
        printf("%d ", p->no);
        p = p->right;
    }
    return 0;


}