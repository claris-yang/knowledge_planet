//
// Created by yangtao on 20-6-3.
//

#include<iostream>
#include<cstring>
using namespace std;
int v[1000005];
int b[1000005];
int f[1000005];
int ks[1000005];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    int begin = 1, end = 0;
    for(int i = 1; i <= n; i++) {
        while( i - ks[begin] >= k && begin <= end )
            begin++;
        while( v[i] < v[ks[end]] && begin <= end )
            end--;
        ks[++end] = i;
        f[i] = v[ks[begin]] ;
    }

    for(int i = k; i < n; i++ )
        cout << f[i] << " ";
    cout << f[n]  << endl;

    begin = 1, end = 0;
    memset(ks, 0, sizeof(ks));
    for(int i = 1; i <= n; i++) {
        while( i - ks[begin] >= k && begin <= end )
            begin++;
        while( v[i] > v[ks[end]] && begin <= end )
            end--;
        ks[++end] = i;
        b[i] = v[ks[begin]] ;
    }

    for(int i = k; i < n; i++ )
        cout << b[i] << " ";
    cout << b[n] << endl;

    return 0;

}
