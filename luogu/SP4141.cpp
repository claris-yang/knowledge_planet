//
// Created by yangtao on 20-8-24.
//

#include<iostream>
using namespace std;
int n,m;
typedef long long ll;
ll phi(ll n) {
    ll ans = n;
    for(int i = 2; i * i <=n ; i++) {
        if(n % i == 0) {
            ans = ans / i * (i - 1);
        }
        while ( n % i == 0 ) {
            n /= i;
        }
    }
    if (n != 1) {
        ans = ans / n * ( n - 1);
    }
    return ans;
}
int main(){
    cin >> m;
    while(m--) {
        cin >> n;
        cout << phi(n) << endl;
    }
    return 0;
}