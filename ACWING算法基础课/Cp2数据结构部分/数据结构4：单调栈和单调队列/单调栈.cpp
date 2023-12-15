#include<iostream>
using namespace std;

const int N = 1e6;
int stk[N];//����ջ
int tt;//ջ��ָ��

void init() {
    tt = 0;
}

void push(int x) { //ѹջ
    stk[++tt] = x;
}

int pop() { //��ջ
    return stk[tt--];
}

bool isempty() { //�ж���
    return tt == 0;
}

int main() {
    int n;
    scanf("%d", &n);
    init(); //��ʼ������ջ
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        while (stk[tt] >= num && !isempty()) { //����ջ����˼��������ĳһ���ʵ�ջ ����������㵥��������ջ
            pop();                          //���ջ���ǵ����������� ���ջ������>=����������ǰ��ջ��������Զ���ᱻ�õ���
        }                                   //��Ϊ��������ֻ���ҵ���ǰ���������Ϊ���������Ľ⣬���Կ���ͨ����ջ�ҵ���������������Ϊ�µ�ջ��
        if (!isempty()) printf("%d ", stk[tt]); //�ǿ�˵���ҵ��˷�����������
        else printf("-1 ");
        push(num);
        //������ ��ʾ��ǰջ������
        //cout << "��" << i << "��ѭ����ջ����" << endl;
        //for(int j = 0; j <= tt; j++) cout << stk[j] << " ";
        //cout << endl;
    }

    return 0;
}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7503120/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������