#ifndef DATA_STRUCT_METHOD_H
#define DATA_STRUCT_METHOD_H

int judgePriority(char, char);
template<class T> SeqStack<T> infix2postfix(char[], int);
template<class T> SeqStack<T> infix2prefix(char[], int);
void calcSub(SeqStack<double>, SeqStack<char>);

/**
 * 🟡利用栈将中缀表达式转换为前缀表达式
 * 中缀表达式：char infix[] = {'a','+','b','-','a','*','(','(','c','+','d',')','/','e','-','f',')','+','g'};
 * @param infix 中缀表达式
 * @param length 第一个元素的数据长度
 * @return 转换出的结果栈
 */
template<class T>
SeqStack<T> infix2prefix(char infix[], int length)
{
    // 准备工作
    SeqStack<char> resultStack; // 结果，遍历时要从栈顶开始遍历
    SeqStack<char> auxiliaryStack;

    // 开始转换
    for (int i = length-1; i >= 0; --i)
    {
        char el = infix[i];
        if (el == ')')
        {
            auxiliaryStack.push(el);
        }
        else if (el == '(')
        {
            while (true)
            {
                char popEl = auxiliaryStack.pop();
                if (popEl != '(' && popEl != ')')
                {
                    resultStack.push(popEl);
                }

                if (popEl == ')')
                {
                    break;
                }
            }
        }
        else if (el == '+' || el == '-' || el == '*' || el == '/')
        {
            while (true)
            {
                if (auxiliaryStack.stackEmpty() || auxiliaryStack.getTop() == ')' || (judgePriority(el, auxiliaryStack.getTop()) >= 0))
                {
                    auxiliaryStack.push(el);
                    break;
                }
                else
                {
                    resultStack.push(auxiliaryStack.pop());
                }
            }
        }
        else
        {
            resultStack.push(el);
        }
    }
    if (!auxiliaryStack.stackEmpty())
    {
        while (!auxiliaryStack.stackEmpty())
        {
            resultStack.push(auxiliaryStack.pop());
        }
    }

    return resultStack;
}

/**
 * 🟡利用栈将中缀表达式转换为后缀表达式
 * 中缀表达式：char infix[] = {'a','+','b','-','a','*','(','(','c','+','d',')','/','e','-','f',')','+','g'};
 * @param infix 中缀表达式
 * @param length 第一个元素的数据长度
 * @return 转换出的结果栈
 */
template<class T>
SeqStack<T> infix2postfix(char infix[], int length)
{
    // 准备工作
    SeqStack<char> resultStack; // 结果，要从栈底开始遍历
    SeqStack<char> auxiliaryStack;

    // 开始转换
    for (int i = 0; i <= length-1; ++i)
    {
        char el = infix[i];
        if (el == '(')
        {
            auxiliaryStack.push(el);
        }
        else if (el == ')')
        {
            while (true)
            {
                char popEl = auxiliaryStack.pop();
                if (popEl != '(' && popEl != ')')
                {
                    resultStack.push(popEl);
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
                if (auxiliaryStack.stackEmpty() || auxiliaryStack.getTop() == '(' || (judgePriority(el, auxiliaryStack.getTop()) > 0))
                {
                    auxiliaryStack.push(el);
                    break;
                }
                else
                {
                    resultStack.push(auxiliaryStack.pop());
                }
            }
        }
        else
        {
            resultStack.push(el);
        }
    }
    if (!auxiliaryStack.stackEmpty())
    {
        while (!auxiliaryStack.stackEmpty())
        {
            resultStack.push(auxiliaryStack.pop());
        }
    }

    return resultStack;
}

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

void calcSub(SeqStack<double> s1, SeqStack<char> s2)
{

}

#endif