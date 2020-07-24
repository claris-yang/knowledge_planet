//
// Created by yangtao on 19-9-20.
//

#include <iostream>
using namespace std;
int a[100005];
long long sum = 0;
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum = (sum+1)/2;
    for(int i = 0; i < n; i++) {
        sum -= a[i];
        if(sum <= 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}