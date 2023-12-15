#include<iostream>
using namespace std;

const int N = 1e7;
int nums[N], q[N]; //输入数据数组 队列存储的是数组下标
int hh, tt; //对头 队尾

void init() {
    hh = 0;
    tt = -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    init(); //初始化队列

    for (int i = 0; i < n; i++) {
        //判断窗口是否滑出队列
        if (hh <= tt && i - k + 1 > q[hh]) hh++; //注意 q[hh]存储的是当前升序排列的数组的下标 如果i - k + 1>q[hh]说明窗口超过了对头，对头应该向队尾移动
        while (hh <= tt && nums[q[tt]] >= nums[i]) tt--; //核心在 nums[q[tt]] >= nums[i] 同单调栈一样，如果在当前升序排列的数组中 新的数小于队尾，在队尾永远不会出现 所以可以剔除
        q[++tt] = i; //一定要把最后一个数加入队尾，应为它可能就是当前的最小数
        if (i >= k - 1) printf("%d ", nums[q[hh]]);
    }

    init();//清空队列为寻找最大值做准备
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;//同最小值相反，这个单调队列应该是升序排列的
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", nums[q[hh]]);
    }
    return 0;

}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7503681/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。