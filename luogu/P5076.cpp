//
// Created by yangtao on 20-6-30.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
multiset <int > m;
int n;

int main() {
    cin >> n;
    m.insert(-0x7fffffff);
    m.insert(0x7fffffff);
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x == 1) {
            auto it=m.lower_bound(y);
            int order=0;
            for(auto i=m.begin();i!=it;i++,order++);
            printf("%d\n",order);
        } else if(x == 2) {
            int order = -1;
            for(int i : m) {
                if(++order == y){
                    printf("%d\n", i);
                    break;
                }
            }
        } else if(x == 3) {
            multiset<int>::iterator it = m.lower_bound(y);
            it--;
            printf("%d\n", *it);

        } else if(x == 4) {
            multiset<int>::iterator it = m.upper_bound(y);
            printf("%d\n", *it);

        } else if(x == 5) {
            m.insert(y);
        }
    }
    return 0;
}