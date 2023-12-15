#include<iostream>
#include<string>

using namespace std;

const int N = 100010;
int q[N];
int tt, hh;//��ͷ ��β

void init() {//���г�ʼ��
    tt = -1;
    hh = 0;
}

void push(int x) {//���β����һ������
    q[++tt] = x;
}

int pop() {//�Ӷ�ͷ����һ������
    return q[hh++];
}

bool isempty() {//�����Ƿ�Ϊ��
    return hh <= tt; //�ǿ�Ϊ true 
}

int query() { //��ѯ��ͷԪ��
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

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7503748/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������