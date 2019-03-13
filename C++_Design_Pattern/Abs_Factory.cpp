#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 用户抽象接口
class IUser
{
    public:
        virtual void GetUser() = 0;
        virtual void InsertUser() = 0;
};


// 部门抽象接口
class IDepartment
{
    public:
        virtual void GetDepartment()=0;
        virtual void InsertDepartment()=0;
};


// ACCESS用户
class CAccessUser:public IUser{
    public:
        virtual void GetUser()
        {
            cout << "Access GetUser" << endl;
        }

        virtual void InsertUser()
        {
            cout << "Access InserUser" << endl;
        }
};


// ACCESS部门
class CAccessDepartment:public IDepartment
{
    public:
        virtual void GetDepartment()
        {
            cout << "ACCESS GetDepartment" << endl;
        }

        virtual void InsertDepartment()
        {
            cout << "ACCESS InserDepartment" << endl;
        }
};


// SQL用户
class CSqlUser:public IUser
{
    public:
        virtual void GetUser()
        {
            cout << "Sql User" << endl;
        }
        
        virtual void InsertUser()
        {
            cout << "Sql User" << endl;
        }
};


// SQL 部门类
class CSqlDepartment:public IDepartment
{
    public:
        virtual void GetDepartment()
        {
            cout << "sql getDepartment" << endl;
        }

        virtual void InsertDepartment()
        {
            cout << "sql InserDepartment" << endl;
        }
};



//抽象工厂
class IFactory
{
    public:
        virtual IUser *CreateUser() = 0;
        virtual IDepartment *CreateDepartment() = 0;
};


// ACCESS 工厂
class AccessFactory:public IFactory
{
    public:
        virtual IUser *CreateUser()
        {
            return new CAccessUser();
        }

        virtual IDepartment *CreateDepartment()
        {
            return new CAccessDepartment();
        }
};

// SQL 工厂
class SqlFacetory:public IFactory
{
    public:
        virtual IUser *CreateUser()
        {
            return new CSqlUser();
        }

        virtual IDepartment *CreateDepartment()
        {
            return new CSqlDepartment();
        }
};


int main(void)
{
    IFactory *factory = new SqlFacetory();
    IUser *user = factory->CreateUser();
    IDepartment *depart = factory->CreateDepartment();
    user->GetUser();
    depart->GetDepartment();

    return 0;
}



