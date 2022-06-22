/** 带头结点的双链表相关代码 **/

#include <iostream>

using namespace std;

/**
 * 结点类型
 */
struct Node
{
    Node* pre;
    int data;
    Node* next;
};

/**
 * 🟢创建带头结点的双链表.
 * 尾插法
 * 手动输入元素
 * @return
 */
Node* createByInput()
{
    // 元素结点个数
    int num = 0;
    cout << "请输入元素个数：";
    cin >> num;

    // 创建头结点
    Node* head = (Node*)malloc(sizeof(Node));
    head->pre = NULL;
    head->next = NULL;
    Node* tail = head; // tail 始终指向最后一个链表最后一个结点

    // 添加元素结点
    Node* p = NULL;
    for (int i = 1; i <= num; ++i)
    {
        p = (Node*)malloc(sizeof(Node));
        cout << "请输入第 " << i << " 个元素：";
        cin >> p->data;
        p->next = NULL;
        p->pre = tail;

        tail->next = p;
        tail = p;
    }

    return head;
}

/**
 * 🟡遍历
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
 * 🔴练习题
 * https://i.imgur.com/7FozOs9.png
 * @param head 双链表
 */
void maxPlace(Node* head)
{
    // 找到最的元素
    Node* max = head->next;
    Node* p = head->next;
    while (p->next)
    {
        p = p->next;
        if (p->data > max->data)
        {
            max = p;
        }
    }

    // 进行移动
    max->pre->next = max->next;
    max->next->pre = max->pre;
    max->next = head->next;
    head->next->pre = max;
    head->next = max;
    max->pre = head;
}

int main()
{
    // 创建带头结点的单链表
    Node* head = createByInput();
    traverse(head, "初始化单链表");

    maxPlace(head);
    traverse(head, "操作过后");

    return 0;
}
