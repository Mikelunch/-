#include<iostream>
using namespace std;

const int N = 1e7;
int e[N], ne[N]; //节点值、节点指向的下一个节点的下标
int head, idx; //head:头节点下标 idx:重点理解 其代表指向未被分配的数组的头部，相当于动态申请链表中的new操作
//idx一般只会向后，其指向的是未使用到的节点 默认不考虑内存泄漏和回收

void init() {//静态链表初始化
    head = -1; //头节点指向空
    idx = 0;//整个数组空间e[N]未被使用，所以指向e[0];
}

void insert_to_head(int x) { //将x值插入到链表头部
    e[idx] = x; //分配内存空间给值为x的新节点
    ne[idx] = head;//新插入的节点指向原先的头节点
    head = idx; //头节点指向新插入的节点
    idx++;//指向新的内存空间
}

void insert_to_k(int k, int x) { //将x插入到下标是k的节点后 
    e[idx] = x;//分配空间
    ne[idx] = ne[k]; //爆改新节点的指向
    ne[k] = idx;//奥拉夫爆改原先下标为k的节点的指向
    idx++;
}


void remove_k_next(int k) { //删除下标为k的节点指向的下一个节点（注意不要搞错）
    ne[k] = ne[ne[k]];
}

void display() {
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
}

int main() {
    int m;
    cin >> m;
    init(); //初始化静态链表
    while (m--) {
        int k, x; //节点位置 节点值
        char op; //操作代码

        cin >> op;

        if (op == 'H') {//执行插入到节点头部操作
            cin >> x;
            insert_to_head(x);
            //display();
        }
        if (op == 'D') { //执行删除操作
            cin >> k;
            if (!k) head = ne[head]; //删除头节点
            remove_k_next(k - 1); //注意输入的k是指第k次操作的数 而k是从1开始的
            //display();
        }
        if (op == 'I') {//指向插入操作
            cin >> k >> x;
            insert_to_k(k - 1, x);//注意输入的k是指第k次操作的数 而k是从1开始的
            //display();
        }
    }
    display();
    return 0;
}