#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 手机软件
class HandsetSoft
{
public:
    virtual void Run()=0;
};


// 游戏软件
class HandsetGame:public HandsetSoft
{
public:
    virtual void Run()
    {
        cout << "运行手机游戏" << endl;
    }
};


// 通讯录软件
class HandsetAddressList:public HandsetSoft
{
public:
    virtual void Run()
    {
        cout << "手机通讯录" << endl;
    }
};


// 手机品牌
class HandsetBrand
{
public:
    void SetHandsetSoft(HandsetSoft *temp)
    {
        m_soft = temp;
    }

    virtual void Run()=0;

protected:
    HandsetSoft *m_soft;
};

// M品牌
class HandsetBrandM:public HandsetBrand
{
public:
    virtual void Run()
    {
        m_soft->Run();
    }
};


// N品牌
class HandsetBrandN:public HandsetBrand
{
public:
    virtual void Run()
    {
        m_soft->Run();
    }
};


int main(void)
{
    HandsetBrand *brand;
    brand = new HandsetBrandM();
    brand->SetHandsetSoft(new HandsetGame());
    brand->Run();
    brand->SetHandsetSoft(new HandsetAddressList());
    brand->Run();

    return 0;
}




