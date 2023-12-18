#include<iostream>
using namespace std;

const int N = 1e6;
int p[N]; //每个节点的父节点

int find(int x) {//返回x的根节点 + 超级加倍路径优化 + 递归 核心中的核心 实在太优雅了
    if (p[x] != x) p[x] = find(p[x]); //如果p[x]没有指向根节点 就递归找到根根节并把路径上的每个节点都指向根节点
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i; //一开始每个数都单独是一个结合

    while (m--) {
        char cmd[2];
        int a, b;
        scanf("%s %d %d", cmd, &a, &b);

        if (cmd[0] == 'Q') {
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
        if (cmd[0] == 'M') {
            scanf("%d %d", &a, &b);
            p[find(a)] = find(b); //将a作为子节点插入到b集合中
        }

    }

    return 0;

}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7518197/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。