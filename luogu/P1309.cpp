//
// Created by yangtao on 19-7-24.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
    int no;
    int pow;
    int score;
    bool operator<(const Person &p) const {
        if(score != p.score) {
            return score > p.score;
        }
        return no < p.no;
    };
};

int n , r , q;
Person person[1000005], wins[1000005], fails[1000005];

void merge() {

    for(int i = 1; i <= n; i++) {
        if(person[2*i-1].pow> person[2*i].pow) {
            wins[i] = person[2*i-1];
            fails[i] = person[2*i];
        } else {
            wins[i] = person[2*i];
            fails[i] = person[2*i - 1];
        }
        wins[i].score += 1;
    }

    int x = 1, y = 1;
    int idx = 1;

    while(x <= n && y <= n) {
        if(wins[x].score == fails[y].score) {
            if(wins[x].no < fails[y].no)
                person[idx++] = wins[x++];
            else
                person[idx++] = fails[y++];
        } else if( wins[x].score > fails[y].score ) {
            person[idx++] = wins[x++];
        } else {
            person[idx++] = fails[y++];
        }
    }
    while(x <= n ) {
        person[idx++] = wins[x++];
    }
    while(y <= n ) {
        person[idx++] = fails[y++];
    }

}

int main() {
    cin >> n >> r >> q;

    for(int i = 1; i <= n * 2; i++) {
        Person p;
        cin >> p.score ;
        p.no = i;
        person[i] = p;
    }

    for(int i = 1; i <= n * 2; i++) {
        cin >> person[i].pow ;
    }

    sort(person + 1, person + n * 2 + 1);

    for(int i = 1; i <= r; i++) {
        merge();
    }

    cout << person[q].no << endl;

    return 0;
}