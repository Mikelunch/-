#include<iostream>
#include<string.h>

using namespace std;

const int N = 1e7;//栈容量
int stk[N]; //栈
int tt; //栈顶指针 用于指向最后一个插入进来的元素

void init() {
    tt = 0; //堆栈初始化
}

void push(int x) { //压栈操作 不考虑爆栈
    stk[++tt] = x;
}

int pop() { //弹栈操作 不考虑空栈情况
    return stk[tt--];
}

bool empty() { //判断是否非空
    return tt == 0;
}

int query() { //访问栈顶元素
    return stk[tt];
}

int main() {
    init(); //初始化堆栈
    int m;
    string cmd;//操作指令
    cin >> m;
    while (m--) {
        cin >> cmd;
        if (!cmd.compare("push")) {
            int x;
            cin >> x;
            push(x);
        }
        if (!cmd.compare("pop")) {
            pop();
        }
        if (!cmd.compare("empty")) {
            if (empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        if (!cmd.compare("query")) {
            cout << query() << endl;
        }
    }
    return 0;
}