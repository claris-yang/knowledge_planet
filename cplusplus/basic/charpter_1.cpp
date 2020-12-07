//
// Created by yangtao on 20-11-10.
//
#include <iostream>
#include <thread>
using namespace std;
void hello () {
    cout << "Hello Concurrent World\n";
}
class background_task {
public :
    void operator()() const {
        cout << "operator" << endl;
    }
};
background_task f;
int main( ) {
    thread t(hello);
    t.join();

    thread t1(f);
    t1.join();

    thread t2{background_task()};
    t2.join();
}
