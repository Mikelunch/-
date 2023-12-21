#include<iostream>
using namespace std;

const int N = 2e5;
int p[N], s[N];//p[n]ָ���丸�ڵ�  size[n]��ʾÿ�������е������

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) p[i] = i, s[i] = 1;  //��ʼ��

    while (m--) {
        char cmd[5];
        int a, b;
        scanf("%s", cmd);

        if (cmd[0] == 'C') {//�������
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) continue; //���2��Ԫ���Ѿ���ͬһ�����б㲻��ִ�в��������
            s[find(b)] += s[find(a)];//ά����ǰ���������еĵ�ĸ�������ά�����ڵ�size[find(x)]����,���������������Ϻϲ�֮ǰ, ΪQ2��ѯ������׼��
            p[find(a)] = find(b); //��a��Ϊ�Ӽ����뵽b������
        }
        else if (cmd[1] == '1') {//ѯ���Ƿ���һ����ͨ��(����)��
            scanf("%d %d", &a, &b);
            if (p[find(a)] == p[find(b)]) printf("Yes\n");
            else printf("No\n");
        }
        else if (cmd[1] == '2') { //ѯ����ͨ���е�ĸ���
            scanf("%d", &a);
            printf("%d\n", s[find(a)]);
        }
    }

    return 0;
}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7523983/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������