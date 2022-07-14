#include "02head.h" // #include 相当于把内容写进来

int main()
{
    char infix[] = {'3','4','*','3','+', '2', '/'};
    double result = calcPostFix(infix, sizeof(infix)/sizeof(infix[0]));

    cout << "打印数据：" << result << endl;
}

