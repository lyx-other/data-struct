#include <iostream>

using namespace std;

/**
 * 顺序表数据类型
 */
struct OrderList
{
    const static int maxSize = 10; // 队列最多可以容纳的数据元素个数
    int length = 0; // 数据中元素的个数，也始终是最后一个元素下一个的下标.
    char arr[maxSize]; // 顺序表
};

/**
 * 🟡创建顺序表
 * @param data 要入顺序表的数据
 * @param n    第一个参数元素的个数
 * @return 顺序表对象的指针
 */
OrderList* create(char data[], int n)
{
    // 申请内存空间
    OrderList* p = (OrderList*)malloc(sizeof(OrderList));
    if (n > p->maxSize)
    {
        free(p);
        p = NULL;
        return p;
    }

    // 赋值
    p->length = n;
    for (int i = 0; i <= n-1; ++i)
    {
        p->arr[i] = data[i];
    }

    return p;
}

/**
 * 🟡向顺序表中插入一个元素
 * @param p    顺序表
 * @param data 要插入的数据
 * @param pos  插入的位置
 * @return 是否插入成功
 */
bool insert(OrderList* p, char data, int pos)
{
    // 检查是否可以插入
    if (p->length == p->maxSize)
    {
        cout << "顺序表已满无法插入" << endl;
        return false;
    }
    if (pos >= p->length+1 || pos <= -1)
    {
        cout << "越界，无法插入." << endl;
        return false;
    }

    // 插入
    for (int i = p->length-1; i >= pos; --i)
    {
        p->arr[i+1] = p->arr[i];
    }
    p->arr[pos] = data;
    p->length++;

    return true;
}

int main()
{
    char originData[] = {'C', 'D', 'E'};
    OrderList* p = create(originData, 3);

    insert(p, '*', 4);

    for (int i = 0; i <= p->length-1; ++i)
    {
        cout << "打印数据：" << p->arr[i] << endl;
    }

    return 0;
}
