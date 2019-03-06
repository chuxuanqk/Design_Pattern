#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Secretary;

// 看股票的同事类(观察对象，观察者)
class StockObserver
{
    public:
        StockObserver(string strname, Secretary *strsub)
        {
            name = strname;
            sub = strsub;
        }

        void Update();

    private:
        string name;
        Secretary *sub;
};

// 秘书类(主题对象，通知者)
class Secretary
{
    public:
        string action;

        void Add(StockObserver ob)
        {
            observers.push_back(ob);
        }

        // 更新
        void Notify()
        {
            vector<StockObserver>::iterator p = observers.begin();
            while(p!=observers.end())
            {
                (*p).Update();
                ++p;
            }
        }

    private:
        vector<StockObserver> observers;
};


void StockObserver::Update()
{
    cout << name << ":" << sub->action << "，不要玩股票了，要开始工作了" << endl;
}


int main()
{
    Secretary *p = new Secretary();    // 创建通知者

    // 观察者
    StockObserver *s1 = new StockObserver("小李", p);
    StockObserver *s2 = new StockObserver("小李", p);

    // 加入通知队列
    p->Add(*s1);
    p->Add(*s2);

    // 事件
    p->action = "老板来了";

    // 通知
    p->Notify();

    return 0;
}



