#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 原型模式
// 抽象基类
class Prototype   
{
    public:
        Prototype(string strName)
        {
            m_strName = strName;
        }
        Prototype()
        {
            m_strName = " ";
        }

        void Show()
        {
            cout << m_strName << endl;
        }

        // 克隆自身的接口
        virtual Prototype *Clone() = 0;

    private:
        string m_strName;
};


// class ConcretePrototype1
class ConcretePrototype1:public Prototype
{
    public:
        ConcretePrototype1(string strName):Prototype(strName){}
        ConcretePrototype1(){}

        virtual Prototype *Clone()
        {
            // 创建一个新的对象分配内存，并传递本身
            ConcretePrototype1 *p = new ConcretePrototype1();
            *p = *this;   // 复制对象
            return p;
        }
};

// class ConcretePrototype2
class ConcretePrototype2:public Prototype
{
    public:
        ConcretePrototype2(string strName):Prototype(strName){}
        ConcretePrototype2(){}

        virtual Prototype *Clone()
        {
            ConcretePrototype2 *p = new ConcretePrototype2();
            *p = *this;   // 复制对象
            return p;
        }
};

// Client
int main()
{
    ConcretePrototype1 *test = new ConcretePrototype1("小王");
    ConcretePrototype2 *test2 = (ConcretePrototype2*)test->Clone();

    test->Show();
    test2->Show();

    return 0;
}


