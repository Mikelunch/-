#include<iostream>
using namespace std;

const int N = 100010;//100000
int h[N], s;//堆内存 当前堆大小

void down(int u) {//将下标为x的值进行下沉操作
    int t = u;//用t表示当前节点和下面一层相连的2个字节的最小值下标
    if (2 * u <= s && h[2 * u] <= h[t]) t = 2 * u;//如果左子节点小于父节点 父节点应该下沉
    if (2 * u + 1 <= s && h[2 * u + 1] <= h[t]) t = 2 * u + 1;//同理右节点 注意这里看出默认先执行与左节点比较后再比较右节点，则左节点是会小于右节点的
    if (t != u) {//父节点确实小于子节点 则交换
        int temp = h[u];
        h[u] = h[t];
        h[t] = temp;
        down(t);//递归下沉 知道到达合适的点位置
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);//先输入到堆内存中再进行初始化操作

    s = n; //注意 默认数组的下标从1开始
    //堆的中间初始化(如何由一维数组形成堆)
    for (int i = n >> 1; i; i--) {//从中间开始 执行 n/2次down即可形成堆
        down(i);
    }

    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[s--];//执行删除操作
        down(1);
    }


    return 0;
}


作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7527310/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。