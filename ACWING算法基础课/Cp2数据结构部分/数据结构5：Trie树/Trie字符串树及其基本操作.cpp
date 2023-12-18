#include<iostream>
using namespace std;

const int N = 1e7;
int son[N][26];//trie����ÿ���ڵ���ӽڵ� ���б�֤�������ַ��ܳ��Ȳ�����N�������N���ڵ�
int cnt[N];//�սڵ� �ýڵ��ʾһ���ַ���ĩβ
int idx;//�ڴ����ָ�� ���� son����ʹ�� ע�� �±�Ϊ0��Ϊ���ڵ�Ҳ�ǿսڵ�
char str[N];//������ַ���

void insertTrie(char str[]) {
    int p = 0;//Ĭ��ָ����ڵ�
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a'; //a - zӳ�䵽 0-25
        if (!son[p][u]) son[p][u] = ++idx;//��ǰ����ڵ�û������ַ���Ӧ���ӽڵ㣬�㴴������
        p = son[p][u]; //p�ڵ��ߵ��ӽڵ�
    }
    cnt[p]++; //���β�ڵ�
}

int quiry(char str[]) {
    int p = 0;//Ĭ�ϴӸ��ڵ㿪ʼ���²���
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0; //δ�ҵ��ӽڵ㼴û������ַ���
        p = son[p][u];//һֱ���²���ƥ��
    }
    return cnt[p]; //���ҵ����ַ��� ����β�ڵ�λ��
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'I') {
            cin >> str;
            insertTrie(str);
        }
        if (cmd == 'Q') {
            cin >> str;
            cout << quiry(str) << endl;
        }
    }
    return 0;
}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7517726/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������