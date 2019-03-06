#include <iostream>

using namespace std;

class Work;
class ForenoonState;
class NoonState;

class State
{
    public:
        virtual void WriteProgram(Work *w) = 0;
};


class Work
{
    public:
        double hour;
        Work();

        void SetState(State *temp)
        {
            current = temp;
        }
        void Writeprogram()
        {
            // 调用State子类的虚函数
            current->WriteProgram(this);
        }
    

    private:
        State *current;
};


class NoonState:public State
{
    public:
        virtual void WriteProgram(Work *w)
        {
            cout << "execute" << endl;
            if((w->hour) <= 13)
                cout << "还不错啦" << endl;
            else
                cout << "不行了，还是睡觉吧" << endl;
        }
};


class ForenoonState:public State
{
    public:
        virtual void WriteProgram(Work *w)
        {
            if((w->hour)<12)
                cout << "现在的精神无敌好" << endl;
            else
            {
                w->SetState(new NoonState());
                w->Writeprogram();   // 注意加上这句
            }
        }
};


// 设置初始状态从ForenoonState开始
Work::Work()
{
    current = new ForenoonState();
}

// 客户端
int main()
{
    Work *mywork = new Work();
    mywork->hour = 15;
    mywork->Writeprogram();
    mywork->hour = 13;
    mywork->Writeprogram();

    return 0;
}


