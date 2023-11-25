#include<iostream>

using namespace std;

const int N = 100000;
int nums[N];
int temp[N];

void merget_sort(int q[], int l, int r) {
    if (l >= r) return; //第零步 设置递归退出条件

    int mid = (l + r) >> 1; //第一步 设置中点为起始点

    merget_sort(q, l, mid), merget_sort(q, mid + 1, r); // 第二步 递归划分要排序的区间 这里递归的原因是先分组在排序

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) // 第三步 将第二步划分的区间的两个有序数组进行双指针排序
        if (q[i] < q[j]) temp[k++] = q[i++]; // 将较小值暂存进临时数组
        else temp[k++] = q[j++];
    while (i <= mid) temp[k++] = q[i++]; //将可能剩下的一部分放入临时数组
    while (j <= r) temp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j]; //将比较好的数据重新放回原来数组
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    merget_sort(nums, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", nums[i]);

    return 0;
}