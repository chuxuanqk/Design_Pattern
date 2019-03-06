#include <iostream>

using namespace std;

// 基类
class COperation
{
    public:
        int m_nFirst;
        int m_nSecond;
        virtual double GetResult()
        {
            double dResult = 0;

            return dResult;
        }
};

// 加法
class AddOperation:public COperation
{
    public:
        virtual double GetResult()
        {
            return m_nFirst+m_nSecond;
        }
};
class SubOperation:public COperation
{
    public:
        virtual double GetResult()
        {
            return m_nFirst-m_nSecond;
        }
};

// 工厂类
class CCalculatorFactory
{
    public:
        static COperation* Create(char cOperator);
};

// 利用多态性，定义一个父类类型指针，使指针指向子类，当调用被子类重写的虚函数时，
// 实际上调用的是子类函数，这是通过多态的方式来实现父类调用子类
COperation* CCalculatorFactory::Create(char cOperator)
{
    COperation *oper;
    switch(cOperator)
    {
        case '+':
            oper = new AddOperation();
            break;
        
        case '-':
            oper = new SubOperation();
            break;
    }
    return oper;
}


int main()
{
    int a=0, b=0;
    char c = 0;


    while(1)
    {
        cout << "请输入a, b:";
        cin >> a >> b;
        cout << "请输入运算符：";
        cin >> c;
        COperation* op = CCalculatorFactory::Create(c);     // 工厂类创建减法类
        op->m_nFirst = a;
        op->m_nSecond = b;
        cout << "a" << c << "b="<< op->GetResult() << endl;
    }
    return 0;
}
