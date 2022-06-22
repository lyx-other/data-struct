/** 带头结点的单链表相关代码 **/

#include <iostream>

using namespace std;

/**
 * 结点类型
 */
struct Node
{
    int data;
    Node* next;
};

/**
 * 🟢创建带头结点的单链表.
 * 没有元素
 * @return 头指针
 */
Node* createEmpty()
{
    // 头结点
    Node headNode;
    headNode.next = NULL;

    return &headNode;
}

/**
 * 🟢创建带头结点的单链表.
 * 有元素.
 * 尾插法
 * @param dataArr 节点中的数据
 * @param n       第一个参数是数组，数组中元素的个数.
 * @return 头指针
 */
Node* createByTail(int dataArr[], int n)
{
    // 准备工作
    Node* r = NULL; // r指针始终指向单链表的最后一个结点

    // 创建头结点
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    r = head;

    // 尾插法添加结点
    for (int i = 0; i <= n-1; ++i)
    {
        Node* newNodeP = (Node*)malloc(sizeof(Node));
        newNodeP->data = dataArr[i];
        newNodeP->next = NULL;

        r->next = newNodeP;
        r = r->next;
    }

    return head;
}

/**
 * 🟢创建带头结点的单链表.
 * 头插法
 * 手动输入元素
 * @return
 */
Node* createByHead()
{
    // 元素结点个数
    int num = 0;
    cout << "请输入元素个数：";
    cin >> num;

    // 创建头结点
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    // 添加元素结点
    Node* p = NULL;
    for (int i = 1; i <= num; ++i)
    {
        p = (Node*)malloc(sizeof(Node));
        p->next = NULL;
        cout << "请输入第 " << i << " 个元素：";
        cin >> p->data;

        p->next = head->next;
        head->next = p;
    }

    return head;
}

/**
 * 🟡遍历带头结点的单链表
 * @param head   head指针
 * @param prompt 提示信息
 */
void traverse(Node* head, string prompt)
{
    // 工作指针p，指向数据元素结点.
    Node* p = head->next;

    // 遍历
    cout << "遍历，" << prompt << "：";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/**
 * 🟡删除有序链表的重复结点
 * @param head 链表头结点
 */
void delRepeatedEle(Node* head)
{
    Node* p = head->next;
    Node* q = NULL;

    while (p->next)
    {
        if (p->data == p->next->data)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
}

/**
 * 🟡拆分单链表，自己写的方法.
 * 将链表中的偶数结点全拿走，形成一个新的链表.
 * 原选的链表剩下的结点还保持原先的相对顺序.
 * @param head 原先的链表
 * @return 新的链表
 */
Node* split1(Node* head)
{
    // 工作指针
    Node* p = head;
    Node* q = head->next;

    // 新的链表
    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead->next = NULL;
    Node* r = newHead;

    // 进行操作
    while (q)
    {
        if (q->data % 2 == 0)
        {
            p->next = q->next; // 删除这个结点

            r->next = q; // 将删除的结点添加到新的链表上
            q->next = NULL;
            r = q;

            q = p->next; // q移动到删除的结点下个结点上
        }
        else
        {
            q = q->next;
            p = p->next;
        }
    }

    return newHead;
}

/**
 * 🟡拆分单链表，教程给的方法.
 * 将链表中的偶数结点全拿走，形成一个新的链表.
 * 原选的链表剩下的结点还保持原先的相对顺序.
 * @param head 原先的链表
 * @return 新的链表
 */
Node* split2(Node* head)
{
    // 工作指针
    Node* p = NULL;
    Node* q = NULL;
    Node* r = NULL;

    // 新链表
    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead->next = NULL;
    r = newHead;
    p = head;

    // 操作
    while (p->next)
    {
        if (p->next->data % 2 == 0)
        {
            q = p->next;
            p->next = q->next;
            q->next = NULL;
            r->next = q;
            r = q;
        }
        else
        {
            p = p->next;
        }
    }
    return newHead;
}

/**
 * 🟡练习题，创建单链表.
 * 要求：https://i.imgur.com/djtSg0c.png
 * @return 创建的单链表.
 */
Node* createNoRepeated()
{
    // 数据元素个数
    int n;
    cout << "请输入数据元素个数：";
    cin >> n;

    // 创建头结点
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    // 工作指针
    Node* r = head; // 指向最后一个数据元素
    Node* q = NULL; // 指向要插入的结点

    // 插入元素
    int numInput;
    for (int i = 1; i <= n; ++i)
    {
        cout << "请输入第 " << i << " 个元素：";
        cin >> numInput;
        if (numInput != r->data)
        {
            q = (Node*)malloc(sizeof(Node));
            q->next = NULL;
            q->data = numInput;

            r->next = q;
            r = q;
        }
    }

    return head;
}

/**
 * 🟡反转单链表[p->next, q]的部分.
 * 用工作指针t，一个一个的拎着往后走，直到最后一个到最前边来.
 * @param head 单链表
 * @param p    p
 * @param q    q
 */
void reversal(Node* head, Node* p, Node* q)
{
    // 工作指针
    Node* t = NULL;

    // 反转
    while (p->next != q)
    {
        t = p->next;
        p->next = t->next;
        t->next = q->next;
        q->next = t;
    }
}

int main()
{
    // 创建带头结点的单链表
    Node* head = createNoRepeated();
    traverse(head, "初始化单链表：");

    // 反转
    reversal(head, head->next, head->next->next->next->next);
    traverse(head, "返转单链表：");

    return 0;
}
