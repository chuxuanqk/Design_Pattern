#include <iostream>
#include <stack>
#include <climits>

using namespace std;

/*
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    cout << exponent << endl;
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent>>1);
    result *= result;
    //判断奇偶
    if((exponent&0x1) == 1)
        result *= base;
    
    return result;
}

void Power_Test()
{
    int i;
    double base;
    double result;
    unsigned int exponent;

    cout << "请输入base, exponent:";
    cin >> base >> exponent;
    result = PowerWithUnsignedExponent(base, exponent);
    cout << "result:" << result << endl; 
}


void Print1ToMaxOfNDigits(int n)
{
    if(n<=0)
        return;

    char* number = new char[n+1];
    number[n] = '\0';

    for(int i=0; i<10; ++i)
    {
        number[0] =  i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n,0 );
    }

    delete[] number;
}


void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }
    
    for(int i=0; i<10; ++i)
    {
        number[index+1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index+1);
    }
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i=0; i<nLength; ++i)
    {
        if(isBeginning0 && number[i]!='0')
            isBeginning0 = false;
        if(!isBeginning0)
        {
            cout << number[i];
        }
    }
    cout << '\t';
}
*/



int main(void)
{
    // Solution *slt = new Solution;
    // int ret = slt->reverse(123);
    // cout << "ret:" << ret << endl;
    cout << INT_MAX << endl;

    return 0;
}


