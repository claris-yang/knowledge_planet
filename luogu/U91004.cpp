//
// Created by yangtao on 19-10-12.
//

#include <iostream>
#include <set>
using namespace std;
int x[10005], y[10005];
set<int> a;
set<int> b;
int main() {
    int n1,n2;
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> x[i];
        a.insert(x[i]);

    }

    cin >> n2;
    for (int j = 0; j < n2; ++j) {
        cin >> y[j];
        b.insert(y[j]);
    }

    int s = 0;
    if( n1 == n2 ) {
        for (int i = 0; i < n1; ++i) {
            if( b.count(x[i])) {
                s++;
            }
        }
        if(s == n1) {
            cout << "A equals B" << endl;
            return 0;
        }
        if(s == 0) {
            cout << "A and B are disjoint" << endl;
            return 0;
        }
    } else if(n1 < n2) {
        for (int i = 0; i < n1; ++i) {
            if( b.count(x[i])) {
                s++;
            }
        }
        if(s == n1) {
            cout << "A is a proper subset of B" << endl;
            return 0;
        }
        if(s == 0) {
            cout << "A and B are disjoint" << endl;
            return 0;
        }
    } else {
        for (int i = 0; i < n2; ++i) {
            if( a.count(y[i])) {
                s++;
            }
        }
        if(s == n2) {
            cout << "B is a proper subset of A" << endl;
            return 0;
        }
        if(s == 0) {
            cout << "A and B are disjoint" << endl;
            return 0;
        }
    }

    cout << "I'm confused!" << endl;
    return 0;
}