#include<cstdio>
#include<iostream>

using namespace std;

const int N = 100000;
int n;
int nums[N];

void quick_sort(int q[], int l, int r) {

    if (l >= r) return; //���㲽 ���õݹ���˳���

    int start_point = q[(l + r) / 2]; // ��һ�� ѡ����ʼ�� һ��ѡ���м����Ӻ��� ���Ҷ˵����׳�ʱ

    int i = l - 1, j = r + 1;//�ڶ��� ����ʼ����ߵ�����С����ʵ�� ����ʼ���ұߵ�����������ʼ��
    while (i < j) {
        do ++i; while (q[i] < start_point); //iָ���ֵ����С����ʼ�����ֹͣ ����˵С�ڵ��� 
        do --j; while (q[j] > start_point); //jָ���ֵ���������ʼ�����ֹͣ  �����Ǵ��ڵ���
        /*
        if(i < j){
            int t = q[i];
            q[i] = q[j];
            q[j] = t;
        }*/
        if (i < j) swap(q[i], q[j]); //���i jû�������򽻻� ע��:Ҫ��ѭ��������� ���ܲ�ֹ��һ��
    }

    quick_sort(q, l, j);//������ �ݹ鴦����ʼ��ǰ�������
    quick_sort(q, j + 1, r); //�ݹ鴦����ʼ���������� ע�������ʼ�����Ҷ˵�����׷������ߵݹ������ ͬ��ȥi��ʱ��

}

int main() {

    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) scanf_s("%d", &nums[i]);

    quick_sort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    return 0;
}