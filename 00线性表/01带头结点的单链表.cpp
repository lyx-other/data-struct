#include <iostream>

using namespace std;

/**
 * 结点
 */
struct Node
{
    int data;
    Node* next;
};

/**
 * 🟡创建带头结点的单链表. <br/>
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
 * 🟡创建带头结点的单链表. <br/>
 * 有元素，<br/>
 * 这个叫尾插法，在天勤数据课中没有讲.
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
 * ⚪️遍历带头结点的单链表
 * @param head head指针
 */
void printLinkList(Node* head)
{
    // 工作指针p，指向数据元素结点.
    Node* p = head->next;

    // 遍历
    while (p)
    {
        cout << "打印数据：" << p->data << endl;
        p = p->next;
    }
}

int main()
{
    int arr[] = {5, 3, 1, 2};
    Node* head = generate(arr, 4);
    printLinkList(head);

    return 0;
}
