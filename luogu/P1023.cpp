//
// Created by yangtao on 19-12-5.
//

#include <iostream>
using namespace std;
int a, b, c;

int ans;
int main() {
    cin >> a >> b >> b;
    while(1) {
        int x, y;
        cin >> x >> y;
        if(x == -1 && y == -1) break;
        if( ans < (x - b) * y + (a - b) * y) {
            ans = ( x - b ) * y + (a - b ) * y;
        }
    }
    return 0;
}