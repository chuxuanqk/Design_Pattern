#include <iostream>
#include <string>


using namespace std;

class Memo;


// 备忘录模式 
// 发起人 类
class Originator
{
    public:
        string state;
        Memo *CreateMemo();
        void SetMemo(Memo *memo);
        void Show()
        {
            cout << "状态：" << state << endl;
        }
};


// 备忘录类
class Memo
{
    public:
        string state;
        Memo(string strState)
        {
            state = strState;
        }
};

Memo *Originator::CreateMemo()
{
    return new Memo(state);
}

void Originator::SetMemo(Memo * memo)
{
    state = memo->state;
}


// 管理者类
class Caretake
{
    public:
        Memo *memo;
};


int main()
{
    Originator *on = new Originator();
    on->state = "on";
    on->Show();

    Caretake *c = new Caretake();
    c->memo = on->CreateMemo();

    on->state = "off";
    on->Show();

    on->SetMemo(c->memo);
    on->Show();

    return 0;
}




