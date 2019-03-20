#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Singelton
{
private:
    // 将构造函数设置为私有，仅供类内部使用
    Singelton(){}
    static Singelton *singel;

public:
    static Singelton* GetInstance()
    {
        if(singel == NULL)
        {
            singel = new Singelton();
        }

        return singel;
    }

};

// 注意静态变量类外初始化
Singelton *Singelton::singel = NULL;


int main()
{
    // 通过类方法GetInstance()， 创建实例
    Singelton *s1 = Singelton::GetInstance();
    Singelton *s2 = Singelton::GetInstance();

    if(s1 == s2)
    {
        cout << "ok" << endl;
    }else
    {
        cout << "no" << endl;
    }

    return 0;
}


