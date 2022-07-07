#include "02head.h" // #include 相当于把内容写进来

int main()
{
    char infix[] = {'a','+','b','-','a','*','(','(','c','+','d',')','/','e','-','f',')','+','g'};
    SeqStack<char> result = infix2postfix(infix, sizeof(infix)/sizeof(infix[0]));
    result.traverseFromBottom("遍历");
}

