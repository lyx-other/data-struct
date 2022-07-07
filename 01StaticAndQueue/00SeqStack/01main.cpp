#include "02head.h"

int main()
{
    char infix[] = {'a','+','b','-','a','*','(','(','c','+','d',')','/','e','-','f',')','+','g'};
    SeqStack<char> result = infix2postfix<char>(infix, sizeof(infix)/sizeof(infix[0]));
    result.traverseFromTop("遍历");
}

