#include<iostream>
#include<string>

using namespace std;

const int N = 100010;
int q[N];
int tt, hh;//队头 队尾

void init() {//队列初始化
    tt = -1;
    hh = 0;
}

void push(int x) {//向队尾插入一个数据
    q[++tt] = x;
}

int pop() {//从队头弹出一个数据
    return q[hh++];
}

bool isempty() {//队列是否为空
    return hh <= tt; //非空为 true 
}

int query() { //查询队头元素
    return q[hh];
}

int main() {
    int m;
    cin >> m;
    init();
    while (m--) {
        int x;
        string cmd;
        cin >> cmd;
        if (!cmd.compare("push")) {
            cin >> x;
            push(x);
        }
        if (!cmd.compare("pop")) {
            pop();
        }
        if (!cmd.compare("empty")) {
            if (isempty()) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        if (!cmd.compare("query")) {
            cout << query() << endl;
        }
    }
    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7503748/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。