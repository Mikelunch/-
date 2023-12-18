#include<iostream>
using namespace std;

const int N = 1e6;
int p[N]; //ÿ���ڵ�ĸ��ڵ�

int find(int x) {//����x�ĸ��ڵ� + �����ӱ�·���Ż� + �ݹ� �����еĺ��� ʵ��̫������
    if (p[x] != x) p[x] = find(p[x]); //���p[x]û��ָ����ڵ� �͵ݹ��ҵ������ڲ���·���ϵ�ÿ���ڵ㶼ָ����ڵ�
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i; //һ��ʼÿ������������һ�����

    while (m--) {
        char cmd[2];
        int a, b;
        scanf("%s %d %d", cmd, &a, &b);

        if (cmd[0] == 'Q') {
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
        if (cmd[0] == 'M') {
            scanf("%d %d", &a, &b);
            p[find(a)] = find(b); //��a��Ϊ�ӽڵ���뵽b������
        }

    }

    return 0;

}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7518197/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������