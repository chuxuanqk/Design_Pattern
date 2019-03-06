#include <iostream>

using namespace std;

// 策略基类
class COperation
{
    public:
        int m_nFirst;
        int m_nSecond;
        virtual double GetResult()
        {
            double dResult=0;
            return dResult;
        }
};

// 策略具体类 ---- 加法类
class AddOperation:public COperation
{
    public:
        AddOperation(int &a, int &b)
        {
            m_nFirst=a;
            m_nSecond=b;
        }
        virtual double GetResult()
        {
            return m_nFirst+m_nSecond;
        }
};

// Context上下文，维护一个队Strategy对象的引用
class Context
{
    public:
        Context(COperation* temp)
        {
            op=temp;
        }
        double GetResult()
        {
            return op->GetResult();
        }
    
    private:
        COperation* op;
};


// 策略和工厂结合, 利用多态性
class Context_1
{
    public:
        Context_1(int first, int second, char cType)
        {
            switch(cType)
            {
                case '+':
                    op = new AddOperation(first, second);
                    break;

                default:
                    break;
            }
        }
        double GetResult()
        {
            return op->GetResult();
        }

    private:
        COperation* op;
};

#define one

#ifdef one
int main()
{
    cout << "one" << endl;
    int a,b;
    char c;
    // Context* context;
    cout << "请输入a, b:";
    cin >> a >> b;
    cout << "请输入运算符：";
    cin >> c;
    switch(c)
    {
        case '+':
        {
            Context* context = new Context(new AddOperation(a, b));
            cout << context->GetResult() << endl;
            break;
        }

        default:
            break;
    }

    return 0;
}
#elif two
int main()
{
    cout << "two" << endl;
    int a,b;
    char c;
    // Context* context;
    cout << "请输入a, b:";
    cin >> a >> b;
    cout << "请输入运算符：";
    cin >> c;
    Context_1* context = new Context_1(a, b, c);
    cout << context->GetResult() << endl;

    return 0;
}

#endif