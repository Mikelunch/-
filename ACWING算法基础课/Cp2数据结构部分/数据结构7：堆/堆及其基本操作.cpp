#include<iostream>
using namespace std;

const int N = 100010;//100000
int h[N], s;//���ڴ� ��ǰ�Ѵ�С

void down(int u) {//���±�Ϊx��ֵ�����³�����
    int t = u;//��t��ʾ��ǰ�ڵ������һ��������2���ֽڵ���Сֵ�±�
    if (2 * u <= s && h[2 * u] <= h[t]) t = 2 * u;//������ӽڵ�С�ڸ��ڵ� ���ڵ�Ӧ���³�
    if (2 * u + 1 <= s && h[2 * u + 1] <= h[t]) t = 2 * u + 1;//ͬ���ҽڵ� ע�����￴��Ĭ����ִ������ڵ�ȽϺ��ٱȽ��ҽڵ㣬����ڵ��ǻ�С���ҽڵ��
    if (t != u) {//���ڵ�ȷʵС���ӽڵ� �򽻻�
        int temp = h[u];
        h[u] = h[t];
        h[t] = temp;
        down(t);//�ݹ��³� ֪��������ʵĵ�λ��
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);//�����뵽���ڴ����ٽ��г�ʼ������

    s = n; //ע�� Ĭ��������±��1��ʼ
    //�ѵ��м��ʼ��(�����һά�����γɶ�)
    for (int i = n >> 1; i; i--) {//���м俪ʼ ִ�� n/2��down�����γɶ�
        down(i);
    }

    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[s--];//ִ��ɾ������
        down(1);
    }


    return 0;
}


���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7527310/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������