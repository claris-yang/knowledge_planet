//
// Created by yangtao on 20-6-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 5;
int t, n;
inline int read()
{
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-48;
    return x*f;
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        unordered_map<int, bool> s;
        for(int i = 0 ; i < n ; i++) {
            int x;
            x = read();
            if( s[x] ) continue;
            s[x] = true;
            printf("%d ", x);
        }
        cout << endl;
    }
    return 0;
}