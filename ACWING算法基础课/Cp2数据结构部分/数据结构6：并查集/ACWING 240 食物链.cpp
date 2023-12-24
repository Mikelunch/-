//����Ĺؼ���������ά�����鼯�е�Ԫ�ص����ڵ�ĳ���
#include<iostream>
using namespace std;


const int N = 2e5;
int p[N], d[N];
int cnt;

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);//�ݴ���ڵ�
        d[x] += d[p[x]]; //�ۼӵ����ڵ�ľ���
        p[x] = t;//���³ɸ��ڵ� ִ��·��ѹ��
    }
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i; //��ʼ��

    while (m--) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        int pa = find(a), pb = find(b);

        if (a > n || b > n) {//�Ƿ����
            //cout << m << ' ' << a << ' '<< b << endl;
            cnt++;
            continue;
        }

        if (t == 1) {//�ж��Ƿ�Ϊͬһ����
            if (pa != pb) {//����ͬһ������ ����ͬһ���� Ĭ��Ϊ�滰
                p[pa] = pb;
                d[pa] = d[b] - d[a];
            }
            else {//��ͬһ������
                if ((d[a] - d[b]) % 3) {
                    cnt++;//d[a] % 3 != d[b] % 3
                    //cout << m << ' ' << a << ' '<< b << endl;
                }
            }
        }
        else {//�жϳԺͱ��ԵĹ�ϵ
            if (pa != pb) {//����ͬһ������ ����ͬһ���� Ĭ��Ϊ�滰
                p[pa] = pb;
                d[pa] = d[b] + 1 - d[a];//�Ӵ��Ը���
            }
            else {//��ͬһ������
                if ((d[a] - d[b] - 1) % 3) {//��ϵ���� 
                    cout << d[a] << ' ' << d[b] << endl;
                    cnt++;
                    //cout << m << ' ' << a << ' '<< b << endl;
                }
            }
        }
    }

    printf("%d", cnt);

    return 0;
}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7529886/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������