#include <iostream>

using namespace std;

const int maxSize = 10;

int main()
{
    int a = 10;
    int* p = &a;

    cout << "打印数据：" << p << endl;
    cout << "打印数据：" << &p << endl;
}
