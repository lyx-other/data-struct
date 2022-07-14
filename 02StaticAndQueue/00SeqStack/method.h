#ifndef _METHOD_H_
#define _METHOD_H_

int judgePriority(char, char);
SeqStack<char> infix2postfix(char[], int);
SeqStack<char> infix2prefix(char[], int);
double calcInFix(char[], int);
char calcSub(SeqStack<double>&, SeqStack<char>&);
double calcSub(double, double, char);
double calcPreFix(char[], int);
double calcSubNormal(double, double, char);

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
 * 🟡利用栈计算中缀表达式的值
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
    while (!s1.stackEmpty() && !s2.stackEmpty())
    {
        calcSub(s1,s2);
    }

    return s1.getTop();
}

/**
 * 🟡利用栈计算前缀表达式的值
 * @param exp 前缀表达式
 * @param n 第一个参数的长度
 * @return 计算结果
 */
double calcPreFix(char exp[], int n)
{
    SeqStack<double> s;

    for (int i = n-1; i >= 0; --i)
    {
        char el = exp[i];
        if (el >= '0' && el <= '9')
        {
            s.push(el-'0');
        }
        else
        {
            double num1 = s.pop();
            double num2 = s.pop();

            double result = calcSubNormal(num1, num2, el);
            s.push(result);
        }
    }

    return s.pop();
}

/**
 * 🟡利用栈计算后缀表达式的值
 * @param exp 后缀表达式
 * @param n   第一个参数的长度
 * @return 计算结果
 */
double calcPostFix(char exp[], int n)
{
    SeqStack<double> s;
    for (int i = 0; i <= n-1; ++i)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            s.push(exp[i] - '0');
        }
        else
        {
            double num1 = s.pop(); // 注意：num1，num2 两个变量不可以省略然后真把s.pop()放到形参中，因为这里有两个出栈，放到形参中，是后边的先执行，而不是前边的先执行.
            double num2 = s.pop();
            double result = calcSub(num1, num2, exp[i]);
            s.push(result);
        }
    }

    return s.pop();
}

/**
 * 🪓工具方法，
 * 计算出栈的两个数，第一个出栈的在右边，第二个出栈的在左边.
 * @param num1 第一个出栈的数
 * @param num2 第二个出栈的数
 * @param op 操作符
 * @return 计算结果
 */
double calcSub(double num1, double num2, char op)
{
    if (op == '+')
    {
        return num2 + num1;
    }
    else if (op == '-')
    {
        return num2 - num1;
    }
    else if (op == '*')
    {
        return num2 * num1;
    }
    else
    {
        if (num1 < MIN)
        {
            throw "0不能作为除数";
        }
        return num2 / num1;
    }
}

/**
 * 🪓工具方法，
 * 计算出栈的两个数，第一个出栈的在左边，第二个出栈的在右边.
 * @param num1 第一个出栈的数
 * @param num2 第二个出栈的数
 * @param op 操作符
 * @return 计算结果
 */
double calcSubNormal(double num1, double num2, char op)
{
    if (op == '+')
    {
        return num2 + num1;
    }
    else if (op == '-')
    {
        return num1 - num2;
    }
    else if (op == '*')
    {
        return num2 * num1;
    }
    else
    {
        if (num2 < MIN)
        {
            throw "0不能作为除数";
        }
        return num1 / num2;
    }
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
char calcSub(SeqStack<double>& s1, SeqStack<char>& s2)
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
                exit(9);
            }
            result = secondPop / firstPop;
        }

        s1.push(result);
    }
}

#endif