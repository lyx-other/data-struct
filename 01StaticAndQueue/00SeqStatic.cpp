/**
 * 顺序栈相关代码
 */

#include <iostream>

using namespace std;

/**
 * 🪓工具方法
 * 判断两个运算符的优先级.
 * @param symbol1 第一个运算符
 * @param symbol2 第二个运算符
 * @return 正数-优先级:第一个>第二个
 *         0-优先级:第一个=第二个
 *        负数-优先级:第一个<第二个
 */
int judgePriority(char symbol1, char symbol2)
{
    if (symbol1 == '+' || symbol1 == '-')
    {
        if (symbol2 == '+' || symbol2 == '-')
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (symbol2 == '+' || symbol2 == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

/**
 * 栈 数据类型
 */
struct SeqStack
{
    static const int maxSize = 20;
    char stack[maxSize];
    int top = -1;
};

/**
 * 🟡入栈
 * @param el 入栈元素
 * @param seqStack 要操作的栈
 */
void push(char el, SeqStack& seqStack)
{
    if (seqStack.top == seqStack.maxSize-1)
    {
        throw "栈满";
    }

    seqStack.top++;
    seqStack.stack[seqStack.top] = el;
}

/**
 * 🟡出栈
 * @param stack 要操作的栈
 * @return 出栈元素
 */
char pop(SeqStack& stack)
{
    if (stack.top == -1)
    {
        throw "栈空";
    }

    return stack.stack[stack.top--];
}

/**
 * 🟡遍历栈
 * 从栈顶开始遍历
 * @param stack 要操作的栈
 * @param prompt 提示
 */
void traverseFromTop(SeqStack& stack, string prompt)
{
    cout << "遍历从栈顶(" << prompt << ")：";
    for (int i = stack.top; i >= 0 ; i--)
    {
        cout << stack.stack[i] << " ";
    }
    cout << endl;
}

/**
 * 🟡遍历栈
 * 从栈底开始遍历
 * @param stack 要操作的栈
 * @param prompt 提示
 */
void traverseFromBottom(SeqStack& stack, string prompt)
{
    cout << "遍历从栈底(" << prompt << ")：";
    for (int i = 0; i <= stack.top ; i++)
    {
        cout << stack.stack[i] << " ";
    }
    cout << endl;
}

/**
 * 🟡利用栈将中缀表达式转换为后缀表达式
 * @param infix 中缀表达式
 * @param length 第一个元素的数据长度
 * @return 转换出的结果栈
 */
SeqStack infix2postfix(char infix[], int length)
{
    // 准备工作
    SeqStack resultStack; // 结果，要从栈底开始遍历
    SeqStack auxiliaryStack;

    // 开始转换
    for (int i = 0; i <= length-1; ++i)
    {
        char el = infix[i];
        if (el == '(')
        {
            push(el, auxiliaryStack);
        }
        else if (el == ')')
        {
            while (true)
            {
                char popEl = pop(auxiliaryStack);
                if (popEl != '(' && popEl != ')')
                {
                    push(popEl, resultStack);
                }

                if (popEl == '(')
                {
                    break;
                }
            }
        }
        else if (el == '+' || el == '-' || el == '*' || el == '/')
        {
            while (true)
            {
                if (auxiliaryStack.top == -1 || auxiliaryStack.stack[auxiliaryStack.top] == '(' || (judgePriority(el, auxiliaryStack.stack[auxiliaryStack.top]) > 0))
                {
                    push(el, auxiliaryStack);
                    break;
                }
                else
                {
                    push(pop(auxiliaryStack), resultStack);
                }
            }
        }
        else
        {
            push(el, resultStack);
        }
    }
    if (auxiliaryStack.top != -1)
    {
        while (auxiliaryStack.top != -1)
        {
            push(pop(auxiliaryStack), resultStack);
        }
    }

    return resultStack;
}

int main()
{
    char infix[] = {'a','+','b','-','a','*','(','(','c','+','d',')','/','e','-','f',')','+','g'};
    SeqStack stack = infix2postfix(infix, sizeof(infix)/sizeof(infix[0]));

    traverseFromBottom(stack, "转换后");
}