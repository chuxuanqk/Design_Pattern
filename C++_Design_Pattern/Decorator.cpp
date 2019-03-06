#include <string>
#include <iostream>

using namespace std;

// 人
class Person
{
    public:
        Person(string strName)
        {
            m_strName = strName;
        }
        
        Person(){}

        virtual void Show()
        {
            cout << "装扮的是：" << m_strName << endl;
        }

    private:
        string m_strName;
};

//装饰类
class Finery:public Person
{
    public:
        void Decorate(Person* component)
        {
            m_component = component;
        }

        virtual void Show()
        {
            m_component->Show();
        }
    // 保护限制，在子类中可以被访问
    protected:
        Person* m_component;
};

//继承装饰类
//T恤
class TShirts:public Finery
{
    public:
        virtual void Show()
        {
            cout << "T Shirts" << endl;
            m_component->Show();
        }
};

//裤子
class BigTrouser:public Finery
{
    public:
        virtual void Show()
        {
            cout<<"Big Trouser"<<endl;
            m_component->Show();
        }
};



int main()
{
    Person *p = new Person("小李");
    BigTrouser *bt = new BigTrouser();
    TShirts *ts = new TShirts();

    bt->Decorate(p);
    ts->Decorate(bt);
    ts->Show();


    return 0;
}