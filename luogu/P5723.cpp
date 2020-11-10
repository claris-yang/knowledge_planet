//
// Created by yangtao on 20-9-25.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, x;
ll sum = 0;
bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int main() {
    cin >> n;
    if(n<2) {
        cout << 0;
        return 0;
    } else if(n==2) {
        cout << 2 << endl << 1 << endl;
        return 0;
    }
    for(int  i = 2; i <= n; i++) {
        if( i % 2 == 0 && i != 2 ) continue;
        if(sum + i > n) {
            cout << x << endl;
            return 0;
        }
        if(is_prime(i)) {
            cout << i << endl;
            sum += i;
            x++;
        }
    }
    return 0;
}

