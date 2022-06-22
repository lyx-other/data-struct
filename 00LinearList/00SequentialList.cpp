/** 顺序表相关代码 **/

#include <iostream>

using namespace std;

/**
 * 顺序表数据类型
 */
struct OrderList
{
    const static int maxSize = 20; // 队列最多可以容纳的数据元素个数
    int length = 0; // 数据中元素的个数，也始终是最后一个元素下一个的下标.
    char arr[maxSize]; // 顺序表
};

/**
 * 🟢创建顺序表
 * @param data 要入顺序表的数据
 * @param n    第一个参数元素的个数
 * @return 顺序表对象的指针
 */
OrderList* createByParameter(char data[], int n)
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
 * 🟢创建顺序表，通过键盘输入.
 * @return 顺序表对象的指针
 */
OrderList* createByInput()
{
    OrderList* p = (OrderList*)malloc(sizeof(OrderList));

    cout << "请输入元素个数：";
    cin >> p->length;

    if (p->length > p->maxSize)
    {
        cout << "创建顺序表失败，元素个数超过最大长度." << endl;
        return NULL;
    }
    for (int i = 0; i <= p->length-1; ++i)
    {
        cout << "请输入 " << i << " 号位置元素：";
        cin >> p->arr[i];
    }

    return p;
}

/**
 * 🟡标准操作，向顺序表中插入一个元素.
 * @param p    顺序表
 * @param data 要插入的数据
 * @param pos  插入的位置
 * @return 是否插入成功
 */
bool insertEle(OrderList* p, char data, int pos)
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

/**
 * 🟡标准操作，从顺序表中删除一个元素.
 * @param p   顺序表
 * @param pos 删除哪个位置的元素
 * @return 指向删除的元素的指针，删除失败时返回NULL.
 */
char* delEle(OrderList* p, int pos)
{
    // 检查是不是可以删除
    if (p->length == 0)
    {
        cout << "没有元素，不可以删除." << endl;
        return NULL;
    }
    if (pos <= -1 || pos >= p->length)
    {
        cout << "越界，不可以删除." << endl;
        return NULL;
    }

    // 删除
    char originEle = p->arr[pos];
    for (int i = pos; i <= p->length-2 ; ++i)
    {
        p->arr[i] = p->arr[i+1];
    }
    p->length--;
    char* originEleP = &originEle;
    return originEleP;
}

/**
 * 🟡标准操作，遍历顺序表.
 * @param p      顺序表
 * @param prompt 提示信息
 */
void traverse(OrderList* p, string prompt)
{
    if (!p)
    {
        cout << "遍历失败，顺序表中没有元素." << endl;
        return;
    }

    cout << "遍历顺序表，" << prompt << "：";
    for (int i = 0; i <= p->length-1; ++i)
    {
        cout << p->arr[i] << " ";
    }
    cout << endl;
}

/**
 * 🔴练习题，删除下标i到j的元素.
 * 方法1
 * @param p    顺序表
 * @param posi 下标i
 * @param posj 下标
 * @return 删除的元素，删除失败返回NULL.
 */
char* delEles1(OrderList*p, int posi, int posj)
{
    // 检查可不可以删除
    if(posi >= posj)
    {
        cout << "参数不正确" << endl;
        return NULL;
    }
    if (posi < 0 || posj > p->length-1)
    {
        cout << "下标越界" << endl;
        return NULL;
    }

    // 缓存下要删除的元素
    int num = posj - posi + 1;
    char* eleArrDel = new char[num] ;
    for (int i = posi; i <= posj; ++i)
    {
        eleArrDel[i-posi] = p->arr[i];
    }

    // 删除元素
    int l = posj + 1;
    for (int k = posi; k <= p->length-posj+posi-2; ++k)
    {
        if (l <= p->length-1)
        {
            p->arr[k] = p->arr[l++]; // 也可以是不变量l p->arr[k] = p->arr[k+posj-posi+1];
        }
        else
        {
            break;
        }
    }
    p->length = p->length - num;

    return eleArrDel;
}

/**
 * 🔴练习题，删除下标i到j的元素.
 * 方法2
 * @param p    顺序表
 * @param posi 下标i
 * @param posj 下标
 * @return 删除的元素，删除失败返回NULL.
 */
char* delEles2(OrderList*p, int posi, int posj)
{
    // 检查可不可以删除
    if(posi >= posj)
    {
        cout << "参数不正确" << endl;
        return NULL;
    }
    if (posi < 0 || posj > p->length-1)
    {
        cout << "下标越界" << endl;
        return NULL;
    }

    // 缓存下要删除的元素
    int num = posj - posi + 1;
    char* eleArrDel = new char[num] ;
    for (int i = posi; i <= posj; ++i)
    {
        eleArrDel[i-posi] = p->arr[i];
    }

    // 删除元素
    for (int i = posj+1; i <= p->length-1; ++i)
    {
        p->arr[i-num] = p->arr[i];
    }
    p->length = p->length - num;

    return eleArrDel;
}

/**
 * 🟡标准操作，返转顺序表.
 * 前后各一个“指针”，不断交换两个位置的元素.
 * 偶数个数列和奇数个元素，结束循环的条件是统一的，不需要分情况写两套代码.
 * @param p
 */
void reversal(OrderList* p)
{
    int left = 0;
    int right = p->length - 1;

    int temp;
    for (; left < right; ++left, --right) // 只要 left < right 就能往下进行
    {
        temp = p->arr[left];
        p->arr[left] = p->arr[right];
        p->arr[right] = temp;
    }
}

int main()
{
    OrderList* p = createByInput();
    traverse(p, "初始化");

    reversal(p);
    traverse(p, "反转后");

    return 0;
}
