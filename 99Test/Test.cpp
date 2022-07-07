#include <iostream>
using namespace std;
#include "Student.h"

void test(Student s)
{
    s.setAge(996);
}

int main()
{
    Student s1;
    s1.setName("李艳兴");
    s1.setAge(10);

    test(s1);

    cout << "打印数据：" << s1.getAge() << endl;
}
