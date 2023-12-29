#include <iostream>
using namespace std;

class AppLib {
public:
    AppLib(){}; //不加{}不是声明
    void run() {
        step1();
        step2();
        step3();
    }
    void step1() {
        cout << "run AppLib.step1()" << endl;
    }
    void step3() {
        cout << "run AppLib.step3()" << endl;
    }
    ~AppLib(){}; //这里必须虚函数，保证子类正常析构
protected:   //这里的延迟接口需要protected
    virtual void step2() = 0;

};

class Application1 : public AppLib {
    void step2() override {
        cout << "run Application1.step2()" << endl;
    }
};

class Application2 : public AppLib {
    void step2() override {
        cout << "run Application2.step2()" << endl;
    }
};

int main() {
    AppLib* applib = new Application1();
    applib->run();
    applib = new Application2();
    applib->run();
    return 0;
}