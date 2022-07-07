#include "02head.h" // #include 相当于把内容写进来

int main()
{
    char infix[] = {'3','/','0','+','4', '*', '5', '*', '(', '2', '+', '3', ')'};
    double result = calcInFix(infix, sizeof(infix)/sizeof(infix[0]));

    cout << "打印数据：" << result << endl;
}

