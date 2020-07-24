//
// Created by yangtao on 19-7-17.
//

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include <pthread>
using namespace std;

void handler(int signo) {
    cout << "signal handler. signo = " << signo <<  endl;
    cout << pthread_self() << enld;
}

void setSignalHandle() {

    struct sigaction act;
    sigemptyset(&act.sa_mask);

    int ret = sigaddset(&act.sa_mask, SIGINT);
    if(ret != 0 ) {
        cout << "sigaddset fail. ret = " << ret << endl;
    }

    act.sa_handler = handler;
    act.sa_flags = 0;

    ret = sigaction(SIGINT, &act, NULL);
    if (ret != 0) {
        cout << "sigaction fail . ret = " << ret << endl;
    }

}
int main() {

    // signal
    signal(SIGHUP, SIG_IGN);
    setSignalHandle();

    cout << getpid() << endl;

    cout << strchr("127.0.0.1:9000", ':') << endl;
    // unistd.h
    sleep(100);
    sleep(100);
    return 0;
}
