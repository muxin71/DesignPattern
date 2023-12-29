#include <iostream>
using namespace std;

class AppLib {
public:
    static void step1();
    static void step3();
};
void AppLib::step1() {
    cout << "run AppLib.step1()" << endl;
}
void AppLib::step3() {
    cout << "run AppLib.step3()" << endl;
}


class Application1 {
public:
    void step2() {
        cout << "run Application1.step2()" << endl;
    }
    void run() {
        AppLib::step1();
        step2();
        AppLib::step3();
    }
};

class Application2 {
public:
    void step2() {
        cout << "run Application2.step2()" << endl;
    }
    void run() {
        AppLib::step1();
        step2();
        AppLib::step3();
    }
};

int main() {
    Application1 app1;
    app1.run();
    Application2 app2;
    app2.run();
    return 0;
}