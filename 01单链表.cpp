#include <iostream>

using namespace std;

const int maxSize = 10;

typedef struct
{
    char data;
    int next; // 下个结点的坐标
} SLNode;

int main()
{
    // 创建数据元素
    SLNode n1;
    n1.data = 'A';
    n1.next = 3;
    SLNode n2;
    n2.data = 'B';
    n2.next = 2;
    SLNode n3;
    n3.data = 'C';
    n3.next = -1;

    // 构建静态链表
    SLNode link[maxSize];
    link[8] = n1;
    link[3] = n2;
    link[2] = n3;
    int p = 8;

    // 遍历静态链表
    while (p != -1)
    {
        cout << "打印数据：" << link[p].data << endl;
        p = link[p].next;
    }
}
