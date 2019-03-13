#include <iostream>

using namespace std;


class Target
{
    public:
        virtual void Request()
        {
            cout << "普通的请求" << endl;
        }
};


class Adaptee
{
    public:
        void SpecificalRequest()
        {
            cout << "特殊请求" << endl;
        }
};


class Adapter:public Target
{
    public:
        virtual void Request()
        {
            ada->SpecificalRequest();
            Target::Request();               // 适配器，顺序添加,加属于空间
        }
        Adapter()
        {
            ada = new Adaptee();
        }
        ~Adapter()
        {
            delete ada;
        }

    private:
        Adaptee *ada;
};


int main()
{
    Adapter *ada = new Adapter();
    ada->Request();

    delete ada;

    return 0;
}

