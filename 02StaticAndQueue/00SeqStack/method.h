#ifndef _METHOD_H_
#define _METHOD_H_

int judgePriority(char, char);
SeqStack<char> infix2postfix(char[], int);
SeqStack<char> infix2prefix(char[], int);
double calcInFix(char[], int);
char calcSub(SeqStack<double>, SeqStack<char>);

/**
 * 🟡利用栈将中缀表达式转换为前缀表达式
 * 中缀表达式：char infix[] = {'a','+','b','-','a','*','(','(','c','+','d',')','/','e','-','f',')','+','g'};
 * @param infix 中缀表达式
 * @param length 第一个元素的数据长度
 * @return 转换出的结果栈
 */
SeqStack<char> infix2prefix(char infix[], int length)
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
SeqStack<char> infix2postfix(char infix[], int length)
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
 * 🟡利用栈计算中值表达式的值
 * @param infix 中值表达式
 * @param n 第一个参数的长度
 * @return 计算结果
 */
double calcInFix(char infix[], int n)
{
    SeqStack<double> s1;
    SeqStack<char> s2;

    for(int i = 0; i <= n-1; i++)
    {
        char el = infix[i];

        if (el >= '0' and el <= '9')
        {
            s1.push(el - '0');
        }
        else if (el == '(')
        {
            s2.push(el);
        }
        else if (el == ')')
        {
            while (true)
            {
                char popEl = calcSub(s1, s2);
                if (popEl == '(')
                {
                    break;
                }
            }
        }
        else // 运算符
        {
            while (true)
            {
                if (s2.stackEmpty() || s2.getTop() == '(' || judgePriority(el,s2.getTop()) > 0)
                {
                    s2.push(el);
                    break;
                }

                calcSub(s1, s2);
            }
        }
    }
    if (!s1.stackEmpty() || !s2.stackEmpty())
    {
        calcSub(s1,s2);
    }

    return s1.getTop();
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

/**
 * 🪓工具方法
 * 用栈来计算中缀表达式的值时调用
 * s1出栈两个操作数、s2栈出栈一个运算符，这三个元素进行一次运算，将运算结果重新压入s1栈，
 * @param s1 s1栈
 * @param s2 s2栈
 * @return s2出栈的元素
 */
char calcSub(SeqStack<double> s1, SeqStack<char> s2)
{
    char symbol = s2.pop();
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
    {
        double firstPop =  s1.pop();
        double secondPop =  s1.pop();

        double result;
        if (symbol == '+')
        {
            result = secondPop + firstPop;
        }
        else if (symbol == '-')
        {
            result = secondPop - firstPop;
        }
        else if (symbol == '*')
        {
            result = secondPop * firstPop;
        }
        else
        {
            if (firstPop < MIN)
            {
                cout << "除数不能为0" << endl;
                exit(-1);
            }
            result = secondPop / firstPop;
        }

        s1.push(result);
    }
}

#endif