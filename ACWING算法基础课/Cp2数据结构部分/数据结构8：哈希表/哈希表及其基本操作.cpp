//第一种哈希表方式：拉链法
#include<iostream>
#include<cstring>
using namespace std;

const int N = 100003; //尽量取里范围外的质数，这样哈希表的存储冲突概率最小
int h[N], e[N], ne[N]; //拉链法存储哈希表 h[]表头 e[] , ne[]链表
int idx; //链表内存分配指针

void init() {
    memset(h, -1, sizeof(h));//表头默认为0
    idx = 0;
}

void myInsert(int x) {
    int k = (x % N + N) % N; //计算将要插入的表头
    e[idx] = x, ne[idx] = h[k], h[k] = idx, idx++; //表头插入
}

bool find(int x) {
    int k = (x % N + N) % N;//计算在哪个链表中
    for (int i = h[k]; i != -1; i = ne[i]) {//遍历链表
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    int m;
    scanf("%d", &m);
    init();//哈希表初始化

    while (m--) {
        char cmd[4];
        scanf("%s", cmd);
        if (cmd[0] == 'I') { //插入
            int x;
            scanf("%d", &x);
            myInsert(x);
        }
        else { //查询
            int x;
            scanf("%d", &x);
            if (find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

//第二种模拟哈希存储方式：开放寻址法
#include<iostream>
#include<cstring>
using namespace std;

//#define egde 2e9

const int N = 200003; //开放寻址法要求一般大于2倍数据 且为质数
int h[N];
const int egde = 0x3f3f3f3f;//实际上一个int h[1] = 0x3f3f3f3f >= 1e9; 这是由memset()函数设置初始值决定的

int find(int x) { //返回数据x在哈希表中的位置
    int k = ((x % N) + N) % N; //计算应该在的位置
    while (h[k] != egde && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;//如果原本的计算的k上有占用则会返回一个没有用过的位置，如果有一样的数据x，则会返回它的下标
}


void init() {
    memset(h, egde, sizeof(h)); //初始化成数据输入范围之外的某个值
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

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7536422/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
