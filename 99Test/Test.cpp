#include <iostream>
using namespace std;
#include "Student.h"

int getNum1()
{
    cout << "打印数据：" << "1111" << endl;
    return 1;
}

int getNum2()
{
    cout << "打印数据：" << "2222" << endl;
    return 1;
}


int add(int num1, int num2)
{
    return num1 + num2;
}

int main()
{
    add(getNum1(), getNum2());
}
