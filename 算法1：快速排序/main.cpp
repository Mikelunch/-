#include<cstdio>
#include<iostream>

using namespace std;

const int N = 100000;
int n;
int nums[N];

void quick_sort(int q[], int l, int r) {

    if (l >= r) return; //第零步 设置递归的退出点

    int start_point = q[(l + r) / 2]; // 第一步 选择起始点 一般选择中间点更加合理 左右端点容易超时

    int i = l - 1, j = r + 1;//第二步 是起始点左边的数都小于其实点 是起始点右边的数都大于起始点
    while (i < j) {
        do ++i; while (q[i] < start_point); //i指向的值必须小于起始点否则停止 不能说小于等于 
        do --j; while (q[j] > start_point); //j指向的值必须大于起始点否则停止  不能是大于等于
        /*
        if(i < j){
            int t = q[i];
            q[i] = q[j];
            q[j] = t;
        }*/
        if (i < j) swap(q[i], q[j]); //如果i j没有相遇则交换 注意:要在循环里面进行 可能不止换一次
    }

    quick_sort(q, l, j);//第三步 递归处理起始点前面的数据
    quick_sort(q, j + 1, r); //递归处理起始点后面的排序 注意如果起始点是右端点就容易发生无线递归的问题 同理去i的时候

}

int main() {

    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) scanf_s("%d", &nums[i]);

    quick_sort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    return 0;
}