#include<iostream>
#include<string>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;//节点值 左指针 右指针 分配地址指针

//初始化
void initList() {
    //注意 这里默认0号节点为头节点 1号节点为尾节点 他们表示链表的边界，不存储实质内容
    r[0] = 1;
    l[1] = 0;
    idx = 2; //分配指针从2开始 所以注意默认第k个数的地址应该是 k+1
}

void insertToRightK(int k, int x) { //在K号节点的右边插入一个节点
    e[idx] = x;//分配内存
    l[idx] = k;
    r[idx] = r[k];//新节点插入
    r[k] = idx;
    l[r[idx]] = idx;//原链表中的节点关系改变
    idx++;
}

void deleteToK(int k) {//删除k号节点
    r[l[k]] = r[k];
    l[r[k]] = l[k]; // 不考虑回收
}

void insertToHead(int x) { //在链表最左端插入x //这里可以优雅的用 insertToRightK(0,x)代替 因为默认头街点就是0且不会变动
    e[idx] = x;
    r[idx] = r[0];
    l[idx] = 0;
    l[r[idx]] = idx;
    r[0] = idx;
    idx++;
}

void insertToTail(int x) {//这里可以优雅的用 insertToRightK(l[1],x)代替，l[1]始终指向最后一个节点，默认1是尾节点且不会改变
    e[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    l[1] = idx;
    r[l[idx]] = idx;
    idx++;
}

int main() {
    int m;
    cin >> m;
    initList();
    while (m--) {
        string cmd;
        int k, x;
        cin >> cmd;
        //cout << cmd << endl;
        if (!cmd.compare("L")) {
            cin >> x;
            //insertToHead(x);  
            insertToRightK(0, x);
        }
        if (!cmd.compare("R")) {
            cin >> x;
            //insertToTail(x);
            insertToRightK(l[1], x);
        }
        if (!cmd.compare("IL")) {
            cin >> k >> x;
            insertToRightK(l[k + 1], x);
        }
        if (!cmd.compare("IR")) {
            cin >> k >> x;
            insertToRightK(k + 1, x);
        }
        if (!cmd.compare("D")) {
            cin >> k;
            deleteToK(k + 1);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";

    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7497129/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。