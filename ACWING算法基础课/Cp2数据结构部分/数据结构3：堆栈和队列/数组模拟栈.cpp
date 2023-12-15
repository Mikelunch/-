#include<iostream>
#include<string.h>

using namespace std;

const int N = 1e7;//ջ����
int stk[N]; //ջ
int tt; //ջ��ָ�� ����ָ�����һ�����������Ԫ��

void init() {
    tt = 0; //��ջ��ʼ��
}

void push(int x) { //ѹջ���� �����Ǳ�ջ
    stk[++tt] = x;
}

int pop() { //��ջ���� �����ǿ�ջ���
    return stk[tt--];
}

bool empty() { //�ж��Ƿ�ǿ�
    return tt == 0;
}

int query() { //����ջ��Ԫ��
    return stk[tt];
}

int main() {
    init(); //��ʼ����ջ
    int m;
    string cmd;//����ָ��
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