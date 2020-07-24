
#include<vector>
#include<iostream>
using namespace std;
const int N = 10005;
int tt, ts, te, n;
char s[10], e[10];

struct Tree {
    int ti, ci, pi;
    Tree(int ti, int ci, int pi) : ti(ti), ci(ci), pi(pi){}
};

vector<Tree> trees;
int f[N];

int getTime(char s[]) {

    int hour = 0, idx = 0;
    while(s[idx] != ':') {
        hour *= 10;
        hour += s[idx++] - '0';
    }
    hour *= 60;

    int min = 0;
    idx++;
    while(s[idx] != '\0') {
       min *= 10;
       min += s[idx++] - '0'; 
    }


    return hour+min;
}
int main() {

    cin >> s >> e >> n;
    ts = getTime(s);
    te = getTime(e);

    //tt = (te + 1440 - ts ) % 1440;

    tt = te - ts;

    for(int i = 0 ;i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0 ) {
            trees.push_back(Tree{a, b, c});
        } else {
            for(int k = 1; k <= c; k <<= 1) {
                c -= k;
                trees.push_back(Tree{k * a, k * b, 1});
            }
            if (c > 0) {
                trees.push_back(Tree{c *a, c *b, 1});
            }
        }
    }

    for(Tree t : trees) {
        if(t.pi == 0 ) {
            for(int j = t.ti; j <= tt; j++) f[j]= max(f[j], f[j-t.ti]+ t.ci);
        } else {
            for(int j = tt; j >= t.ti; j-- ) f[j] = max(f[j], f[j-t.ti] + t.ci);
        }
    }


    cout << f[tt];

    return 0;
}