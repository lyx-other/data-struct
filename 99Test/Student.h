//
// Created by Administrator on 2022/7/7.
//

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student
{
private:
    string name;
    int age;
public:
    const string &getName() const;
    void setName(const string &name);
    int getAge() const;
    void setAge(int age);
};

const string &Student::getName() const
{
    return name;
}

void Student::setName(const string &name)
{
    Student::name = name;
}

int Student::getAge() const
{
    return age;
}

void Student::setAge(int age)
{
    Student::age = age;
}

#endif
