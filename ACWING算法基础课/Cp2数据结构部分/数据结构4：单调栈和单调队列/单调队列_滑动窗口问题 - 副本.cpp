#include<iostream>
using namespace std;

const int N = 1e7;
int nums[N], q[N]; //������������ ���д洢���������±�
int hh, tt; //��ͷ ��β

void init() {
    hh = 0;
    tt = -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    init(); //��ʼ������

    for (int i = 0; i < n; i++) {
        //�жϴ����Ƿ񻬳�����
        if (hh <= tt && i - k + 1 > q[hh]) hh++; //ע�� q[hh]�洢���ǵ�ǰ�������е�������±� ���i - k + 1>q[hh]˵�����ڳ����˶�ͷ����ͷӦ�����β�ƶ�
        while (hh <= tt && nums[q[tt]] >= nums[i]) tt--; //������ nums[q[tt]] >= nums[i] ͬ����ջһ��������ڵ�ǰ�������е������� �µ���С�ڶ�β���ڶ�β��Զ������� ���Կ����޳�
        q[++tt] = i; //һ��Ҫ�����һ���������β��ӦΪ�����ܾ��ǵ�ǰ����С��
        if (i >= k - 1) printf("%d ", nums[q[hh]]);
    }

    init();//��ն���ΪѰ�����ֵ��׼��
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;//ͬ��Сֵ�෴�������������Ӧ�����������е�
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", nums[q[hh]]);
    }
    return 0;

}

���ߣ�ConstantZ
���ӣ�https ://www.acwing.com/activity/content/code/content/7503681/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������