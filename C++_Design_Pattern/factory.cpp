#include <string>
#include <iostream>

using namespace std;

// 实例基类，相当于Product
class LeiFeng
{
    public:
        virtual void Sweep()
        {
            cout << "雷锋扫地" << endl;
        }
};

// ConcreteProduct
class Student:public LeiFeng
{
    public:
        virtual void Sweep()
        {
            cout << "大学生扫地" << endl;
        }
};

// ConcreteProduct
class Volenter:public LeiFeng
{
    public:
        virtual void Sweep()
        {
            cout << "志愿者" << endl;
        }
};

// 工厂基类Creator
class LeiFengFactory
{
    public:
        virtual LeiFeng *CreateLeiFeng()
        {
            return new LeiFeng();
        }
};

// 工厂具体类
class StudentFactory:public LeiFengFactory
{
    public:
        virtual LeiFeng* CreateLeiFeng()
        {
            return new Student();
        }
};


class VolenterFactory:public LeiFengFactory
{
    public:
        virtual LeiFeng *CreateLeiFeng()
        {
            return new Volenter();
        }
};



// 客户端
int main(void)
{
    LeiFengFactory *sf= new LeiFengFactory();
    LeiFeng *s = sf->CreateLeiFeng();
    s->Sweep();

    VolenterFactory *vf = new VolenterFactory();
    LeiFeng *v = vf->CreateLeiFeng();
    v->Sweep();

    delete v;
    delete vf;
    delete s;
    delete sf;

    return 0;
}


