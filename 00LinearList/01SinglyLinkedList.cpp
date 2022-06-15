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

int main()
{
    int arr[] = {1, 2, 3, 3};
    Node* head = generate(arr, 4);
    printLinkList(head);

    delRep(head);
    printLinkList(head);

    return 0;
}
