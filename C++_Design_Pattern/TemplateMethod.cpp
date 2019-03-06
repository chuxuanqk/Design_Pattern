#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AbstractClass
{
    public:
        void Show()
        {
            cout << "我是" << GetName() << endl;
        }
    
    protected:
        virtual string GetName() = 0;
};


class Naruto:public AbstractClass
{
    protected:
        virtual string GetName()
        {
            return "火影史上最帅的六代目---鸣人";
        }
};


class OnePice:public AbstractClass
{
    protected:
        virtual string GetName()
        {
            return "草帽小子----路飞";
        }
};


int main()
{
    Naruto *man = new Naruto();
    man->Show();

    OnePice *man2 = new OnePice();
    man2->Show();

    return 0;
}

