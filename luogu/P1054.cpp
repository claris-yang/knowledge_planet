//
// Created by yangtao on 20-7-7.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
const int P = 13331;
map<char, int > priority;
stack<char> op;
stack<int> num;

void eval() {
    char c = op.top(); op.pop();
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();

    if(c == '+' ) num.push((a+b) % P);
    else if(c == '-') num.push(((a-b) % P + P) % P);
    else if(c == '*') num.push(a * b % P);
    else {
        int t = 1;
        while(b--) t = t * a % P;
        num.push(t);
    }
}
int calc(string expr, int a ) {
    op = stack<char>();
    num = stack<int>();
    for(int i = 0; i <expr.size(); i++) {
        if(expr[i] == ' ') continue;
        if (expr[i] >= '0' && expr[i] <= '9') {
            int j = i, number = 0;
            while(j <expr.size() && expr[j] >= '0' && expr[j] <= '9') {
                number = number  * 10 + expr[j] - '0';
                j++;
            }
            i = j - 1;
            num.push(number);
        } else if(expr[i] == 'a') num.push(a);
        else {
            char c = expr[i];
            if(c == '(') op.push(c);
            else if(c == ')') {
                while(op.top() != '(') eval();
                op.pop();
            } else {
                while(op.size() && priority[op.top()] >= priority[c]) eval();
                op.push(c);
            }
        }
    }
    while(op.size()) eval();
    return num.top();
}
bool check(string expr1, string expr2) {
    for(int  i = 0;i < 1000; i++) {
        if(calc(expr1, i) != calc(expr2, i))
            return false;
    }
    return true;
}
int main() {
    char ops[] = "(+-*^";
    for(int i = 0; i < 5; i++)
        priority[ops[i]] = i;
    string expr, line;
    getline(cin, expr);
    int n;
    cin >> n;
    getline(cin , line);
    for(int i = 0 ;i < n ; i++) {
        getline(cin , line);
        if(check(expr, line))
            printf("%c", 'A' + i);
            //cout << 'A' + i;
    }
    return 0;
}