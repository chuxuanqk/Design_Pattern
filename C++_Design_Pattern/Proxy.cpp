#include <string>
#include <iostream>

using namespace std;


// 定义接口
class Interface
{
    public:
        virtual void Request()=0;     // 纯虚函数
};


// 真实类, 继承Interface
class RealClass:public Interface
{
    public:
        virtual void Request()
        {
            cout << "真实的请求" << endl;
        }
};

// 代理类, 继承Interface
class ProxyClass:public Interface
{
    public:
        virtual void Request()
        {
            m_realClass = new RealClass();
            m_realClass->Request();
        }
        ~ProxyClass()
        {
            delete m_realClass;
        }
    private:
        RealClass* m_realClass;
};

int main()
{
    ProxyClass *test = new ProxyClass();
    test->Request();

    return 0;
}


