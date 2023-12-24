#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 2e5;
int h[N];//���ڴ�����
int hp[N], ph[N];//hp[i] = k;���е�i���ڵ�ָ��ph[]������k���±� ph[k] = i;//h[]���ڴ�������k�±��Ӧ���е�i���ڵ�
int idx = 0;//���ڴ����ָ��
int cnt = 0;//��Ų�������
void heap_swap(int a, int b) {//�������� a , b 2���ڵ��λ��
    swap(ph[hp[a]], ph[hp[b]]);//�Ƚ��������±�Ͷѽڵ��ӳ��
    swap(hp[a], hp[b]);//��ν����ѽڵ㵽�����±��ӳ��
    swap(h[a], h[b]);//��󽻻��ڵ�ֵ
}

void down(int u) {
    int t = u;//t�ݴ游�ڵ��2���ӽڵ�����Сֵ���±���Ĭ��һ��ʼu�Ǹ��ڵ� 
    if (u * 2 <= idx && h[t] >= h[u * 2]) t = u * 2;//���ڵ�����ӽڵ�Ƚ�
    if (u * 2 + 1 <= idx && h[t] >= h[u * 2 + 1]) t = u * 2 + 1;//�����ӽڵ�Ƚ�
    if (t != u) {
        heap_swap(t, u);
        down(t);//�鿴�Ƿ���Ҫ�����³�
    }
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char cmd[3];
        scanf("%s", cmd);
        if (!strcmp(cmd, "I")) {//ִ�в������
            int x;
            scanf("%d", &x);
            idx++;//������ڴ�
            h[idx] = x;
            cnt++;//��������++ ��¼���ǵڼ��������
            ph[cnt] = idx, hp[idx] = cnt;
            up(idx);//Ĭ�ϴӶѵ����²���� ���������ϸ�
        }
        else if (!strcmp(cmd, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(cmd, "DM")) {
            heap_swap(1, idx);//������С���������
            idx--;//���ڴ�--
            down(1);//�³������
        }
        else if (!strcmp(cmd, "D")) {//ɾ����k����
            int k;
            scanf("%d", &k);
            k = ph[k];//�ҵ��ڶ��еĽڵ�  �ر�ע�����Ҫ����ph[k]�����ı� ӦΪ����Ҳ���õ�������1 
            heap_swap(k, idx);//ע�������ǽ��� �����Ǹ��� ��Ϊ�����-- 
            //ע�����ﲻ��ֱ�� ph[k]���������� ��Ϊ��down �� up���Ի��õ�ph[k]��ԭֵ ���Ҫ����ph[k] ���һ���size!!!!
            idx--;
            down(k), up(k);//��ִ������֮һ
        }
        else {//�޸ĵ�k����
            int k, x;
            scanf("%d %d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}


���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7528109/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������