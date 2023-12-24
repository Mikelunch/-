#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 2e5;
int h[N];//堆内存数组
int hp[N], ph[N];//hp[i] = k;堆中第i个节点指向ph[]数组中k的下标 ph[k] = i;//h[]堆内存数组中k下标对应堆中第i个节点
int idx = 0;//堆内存分配指针
int cnt = 0;//存放操作次数
void heap_swap(int a, int b) {//交换堆中 a , b 2个节点的位置
    swap(ph[hp[a]], ph[hp[b]]);//先交换数组下标和堆节点的映射
    swap(hp[a], hp[b]);//其次交换堆节点到数组下标的映射
    swap(h[a], h[b]);//最后交换节点值
}

void down(int u) {
    int t = u;//t暂存父节点和2个子节点中最小值的下标且默认一开始u是父节点 
    if (u * 2 <= idx && h[t] >= h[u * 2]) t = u * 2;//父节点和左子节点比较
    if (u * 2 + 1 <= idx && h[t] >= h[u * 2 + 1]) t = u * 2 + 1;//左右子节点比较
    if (t != u) {
        heap_swap(t, u);
        down(t);//查看是否需要继续下沉
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
        if (!strcmp(cmd, "I")) {//执行插入操作
            int x;
            scanf("%d", &x);
            idx++;//分配堆内存
            h[idx] = x;
            cnt++;//操作次数++ 记录这是第几个插入点
            ph[cnt] = idx, hp[idx] = cnt;
            up(idx);//默认从堆的最下层插入 所以数据上浮
        }
        else if (!strcmp(cmd, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(cmd, "DM")) {
            heap_swap(1, idx);//交换最小数和最大数
            idx--;//堆内存--
            down(1);//下沉最大数
        }
        else if (!strcmp(cmd, "D")) {//删除第k个数
            int k;
            scanf("%d", &k);
            k = ph[k];//找到在堆中的节点  特别注意这里：要保护ph[k]不被改变 应为后面也会用到！！！1 
            heap_swap(k, idx);//注意这里是交换 而不是覆盖 因为后面会-- 
            //注意这里不能直接 ph[k]做后续操作 因为在down 和 up中仍会用到ph[k]的原值 因此要保护ph[k] 否找会变成size!!!!
            idx--;
            down(k), up(k);//仅执行其中之一
        }
        else {//修改第k个数
            int k, x;
            scanf("%d %d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}


作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7528109/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。