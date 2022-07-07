#include <iostream>
using namespace std;
#include "Student.h"

void test(Student s)
{
    s.setAge(996);
}

void test2(Student a[])
{
    a[0].setAge(99);
}

int main()
{
    Student s1;
    s1.setAge(-1);
    Student arr[3];
    arr[0] = s1;

    cout << "打印数据：" << arr[0].getAge() << endl;

    test2(arr);

    cout << "打印数据：" << arr[0].getAge() << endl;
}
