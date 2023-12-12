#include<iostream>
#include<string>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;//�ڵ�ֵ ��ָ�� ��ָ�� �����ַָ��

//��ʼ��
void initList() {
    //ע�� ����Ĭ��0�Žڵ�Ϊͷ�ڵ� 1�Žڵ�Ϊβ�ڵ� ���Ǳ�ʾ����ı߽磬���洢ʵ������
    r[0] = 1;
    l[1] = 0;
    idx = 2; //����ָ���2��ʼ ����ע��Ĭ�ϵ�k�����ĵ�ַӦ���� k+1
}

void insertToRightK(int k, int x) { //��K�Žڵ���ұ߲���һ���ڵ�
    e[idx] = x;//�����ڴ�
    l[idx] = k;
    r[idx] = r[k];//�½ڵ����
    r[k] = idx;
    l[r[idx]] = idx;//ԭ�����еĽڵ��ϵ�ı�
    idx++;
}

void deleteToK(int k) {//ɾ��k�Žڵ�
    r[l[k]] = r[k];
    l[r[k]] = l[k]; // �����ǻ���
}

void insertToHead(int x) { //����������˲���x //����������ŵ��� insertToRightK(0,x)���� ��ΪĬ��ͷ�ֵ����0�Ҳ���䶯
    e[idx] = x;
    r[idx] = r[0];
    l[idx] = 0;
    l[r[idx]] = idx;
    r[0] = idx;
    idx++;
}

void insertToTail(int x) {//����������ŵ��� insertToRightK(l[1],x)���棬l[1]ʼ��ָ�����һ���ڵ㣬Ĭ��1��β�ڵ��Ҳ���ı�
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

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7497129/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������