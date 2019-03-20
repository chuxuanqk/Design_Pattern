#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 请求
class Request
{
public:
    string m_strContent;
    int m_nNumber;
};


// 管理者
class Manager
{
public:
    Manager(string temp)
    {
        name = temp;
    }

    void SetSuccessor(Manager* temp)
    {
        manage = temp;
    }

    virtual void GetRequest(Request* request)=0;

protected:
    Manager* manage;
    string name;
};


// 经理
class CommonManager:public Manager
{
public:
    CommonManager(string strTemp):Manager(strTemp){}
    
    virtual void GetRequest(Request* request)
    {

        if(request->m_nNumber>=0&&request->m_nNumber<10)
        {
            cout << name << "处理了" << request->m_nNumber << "个请求" << endl;
        }else{
            manage->GetRequest(request);
        }

    }
};


// 总监
class MajorDomo:public Manager
{
public:
    MajorDomo(string name):Manager(name){}

    virtual void GetRequest(Request* request)
    {
        if(request->m_nNumber>=10)
        {
            cout << name << "处理了" << request->m_nNumber << "个请求" << endl;
        }
    }
};


int main()
{
    Manager* common = new CommonManager("张经理");
    Manager* major = new MajorDomo("李总监");

    common->SetSuccessor(major);

    Request* req = new Request();
    req->m_strContent = 33;
    common->GetRequest(req);

    req->m_nNumber = 3;
    common->GetRequest(req);

    return 0;
}


