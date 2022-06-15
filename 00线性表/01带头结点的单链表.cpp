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
 * 创建带头结点的单链表.
 * @return 头指针
 */
Node* generate()
{
    // 头结点
    Node headNode;
    headNode.next = NULL;

    return &headNode;
}

int main()
{
    return 0;
}
