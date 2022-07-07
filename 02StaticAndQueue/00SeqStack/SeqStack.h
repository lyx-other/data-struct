#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

/**
 * 顺序栈类
 * @tparam T 栈中的泛型
 */
template<class T>
class SeqStack
{
private:
    static const int MAX_SIZE = 20;
    T stack[MAX_SIZE];
    int top = -1;
public:
    void push(T);
    T pop();
    void traverseFromTop(string);
    void traverseFromBottom(string);
    bool stackEmpty();
    T getTop();
};

/**
 * 🟡遍历栈
 * 从栈底开始遍历
 * @param prompt 提示
 */
template<class T>
void SeqStack<T>::traverseFromBottom(string prompt)
{
    cout << "遍历从栈底(" << prompt << ")：";
    for (int i = 0; i <= top ; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

/**
 * 🟡遍历栈
 * 从栈顶开始遍历
 * @param prompt 提示
 */
template<class T>
void SeqStack<T>::traverseFromTop(string prompt)
{
    cout << "遍历从栈顶(" << prompt << ")：";
    for (int i = top; i >= 0 ; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

/**
 * 🟡出栈
 * @return 出栈元素
 */
template<class T>
T SeqStack<T>::pop()
{
    if (top == -1)
    {
        throw "栈空";
    }

    return stack[top--];
}

/**
 * 🟡入栈
 * @param el 入栈元素
 */
template<class T>
void SeqStack<T>::push(T el)
{
    if (top == MAX_SIZE-1)
    {
        throw "栈满";
    }

    top++;
    stack[top] = el;
}

/**
 * 🟡判断是否栈空
 * @return ture-栈空  false-栈满
 */
template<class T>
bool SeqStack<T>::stackEmpty()
{
    return top == -1;
}

/**
 * 🟡获得栈顶元素
 * @return
 */
template<class T>
T SeqStack<T>::getTop()
{
    return stack[top];
}

#endif