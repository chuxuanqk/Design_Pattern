#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 烤肉师傅
class Barbucer
{
public:
    void MakeMutton()
    {
        cout << "烤羊肉" << endl;
    }

    void MakeChickenWing()
    {
        cout << "烤鸡翅膀" << endl;
    }
};


// 抽象命令类
class Command
{
public:
    Command(Barbucer *temp)
    {
        receiver = temp;
    }
    virtual void ExecuteCmd() = 0;

protected:
    Barbucer *receiver;
};


// 烤羊肉命令
class BakeMuttonCmd:public Command
{
public:
    BakeMuttonCmd(Barbucer *temp):Command(temp){}
    virtual void ExecuteCmd()
    {
        receiver->MakeMutton();
    }
};

// 烤鸡翅
class ChickenWingCmd:public Command
{
public:
    ChickenWingCmd(Barbucer *temp):Command(temp){}

    virtual void ExecuteCmd()
    {
        receiver->MakeChickenWing();
    }
};


// 服务员类
class Waiter
{
public:
    void SetCmd(Command *temp)
    {
        m_commandList.push_back(temp);
        cout << "增加订单" << endl;
    }

    // 通知执行
    void Notfiy()
    {
        vector<Command*>::iterator p = m_commandList.begin();
        while(p!=m_commandList.end())
        {
            (*p)->ExecuteCmd();
            p++;
        }
    }

protected:
    vector<Command*> m_commandList;
};


int main()
{
    // 店里添加烤肉师傅、菜单、服务员等顾客
    Barbucer* barbucer = new Barbucer();
    Command* cmd = new BakeMuttonCmd(barbucer);
    Command* cmd2 = new ChickenWingCmd(barbucer);
    Waiter* girl = new Waiter();

    // 点菜
    girl->SetCmd(cmd);
    girl->SetCmd(cmd2);
    // 服务员通知
    girl->Notfiy();

    return 0;
}



