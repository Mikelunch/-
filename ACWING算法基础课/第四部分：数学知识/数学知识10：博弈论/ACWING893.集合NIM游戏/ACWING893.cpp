#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<cstring>
using namespace std;
const int N = 110, M = 10086;//ʯͷ���� ÿ��ʯ����
int n, m;
int s[N], f[M];//s��ʾ�����õ�ʯ������ fΪSG����ֵ

int sg(int x) {//����x�����µ�sg����
    if (f[x] != -1) {//�þ����Ѿ������
        return f[x];
    }
    //����������x�����½������ܵ���ľ���
    unordered_set<int> S;
    for (int i = 0; i < m; i++) {//ö�ٿ�ѡʯ�Ӷѵ�ʯ����
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));//�����ǰ�����µ�ʯ��������ȡ����ǰ���µ�ʯ��������DFSֱ������ȡ
    }
    //�жϼ����в����ڵ���С��Ȼ���Ƕ��٣��õ�SGֵ   
    for (int i = 0; ; i++) {
        if (!S.count(i)) {
            return f[x] = i;
        }
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) scanf("%d", &s[i]);
    cin >> n;

    memset(f, -1, sizeof f);
    int res = 0;//�洢����sg��ֵ
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= sg(x);//����ʼʯ�ӵ�sgֵ��ɸ���NIM��Ϸ����Ԥ���ʤ���߱ذ�̬
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}