//
// Created by yangtao on 19-6-13.
//

#include <iostream>
using namespace std;

class Library {
public:
    void run() {
        step1();
        if(step2()) {
            step3();
        }
        for(int i = 0 ;i < 4; i++) {
            step4();
        }
        step5();
    }
    ~Library();
protected:
    void step1();
    void step3();
    void step5();
    virtual void step2() = 0;
    virtual void step4() = 0;

};

class Application : Library{
public:
    virtual void step2();
    virtual void step4();
};

int main() {

    return 0;
}