//��һ�ֹ�ϣ��ʽ��������
#include<iostream>
#include<cstring>
using namespace std;

const int N = 100003; //����ȡ�ﷶΧ���������������ϣ��Ĵ洢��ͻ������С
int h[N], e[N], ne[N]; //�������洢��ϣ�� h[]��ͷ e[] , ne[]����
int idx; //�����ڴ����ָ��

void init() {
    memset(h, -1, sizeof(h));//��ͷĬ��Ϊ0
    idx = 0;
}

void myInsert(int x) {
    int k = (x % N + N) % N; //���㽫Ҫ����ı�ͷ
    e[idx] = x, ne[idx] = h[k], h[k] = idx, idx++; //��ͷ����
}

bool find(int x) {
    int k = (x % N + N) % N;//�������ĸ�������
    for (int i = h[k]; i != -1; i = ne[i]) {//��������
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    int m;
    scanf("%d", &m);
    init();//��ϣ���ʼ��

    while (m--) {
        char cmd[4];
        scanf("%s", cmd);
        if (cmd[0] == 'I') { //����
            int x;
            scanf("%d", &x);
            myInsert(x);
        }
        else { //��ѯ
            int x;
            scanf("%d", &x);
            if (find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

//�ڶ���ģ���ϣ�洢��ʽ������Ѱַ��
#include<iostream>
#include<cstring>
using namespace std;

//#define egde 2e9

const int N = 200003; //����Ѱַ��Ҫ��һ�����2������ ��Ϊ����
int h[N];
const int egde = 0x3f3f3f3f;//ʵ����һ��int h[1] = 0x3f3f3f3f >= 1e9; ������memset()�������ó�ʼֵ������

int find(int x) { //��������x�ڹ�ϣ���е�λ��
    int k = ((x % N) + N) % N; //����Ӧ���ڵ�λ��
    while (h[k] != egde && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;//���ԭ���ļ����k����ռ����᷵��һ��û���ù���λ�ã������һ��������x����᷵�������±�
}


void init() {
    memset(h, egde, sizeof(h)); //��ʼ�����������뷶Χ֮���ĳ��ֵ
}
int main() {
    int m;
    scanf("%d", &m);
    init();

    while (m--) {
        char cmd[5];
        scanf("%s", cmd);
        int x;
        scanf("%d", &x);
        if (cmd[0] == 'I') {
            h[find(x)] = x;
        }
        else {
            if (h[find(x)] == x) puts("Yes");
            else puts("No");
        }

    }

    return 0;
}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7536422/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
