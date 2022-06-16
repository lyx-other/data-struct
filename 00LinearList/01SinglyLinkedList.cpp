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
Node* generate()
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
Node* generate(int dataArr[], int n)
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
 * 🟡遍历带头结点的单链表
 * @param head head指针
 */
void printLinkList(Node* head)
{
    // 工作指针p，指向数据元素结点.
    Node* p = head->next;

    // 遍历
    cout << "遍历：";
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
void delRep(Node* head)
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
}

int main()
{
    // 创建带头结点的单链表
    int arr[] = {1, 2, 3, 3};
    Node* head = generate(arr, 4);
    printLinkList(head);

    // 拆分单链表
    Node* newHead = split(head);
    printLinkList(newHead);

    return 0;
}
