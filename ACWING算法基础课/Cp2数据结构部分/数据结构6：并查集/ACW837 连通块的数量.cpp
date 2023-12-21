#include<iostream>
using namespace std;

const int N = 2e5;
int p[N], s[N];//p[n]指向其父节点  size[n]表示每个集合中点的数量

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) p[i] = i, s[i] = 1;  //初始化

    while (m--) {
        char cmd[5];
        int a, b;
        scanf("%s", cmd);

        if (cmd[0] == 'C') {//插入操作
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) continue; //如果2个元素已经在同一集合中便不用执行插入操作了
            s[find(b)] += s[find(a)];//维护当前整个集合中的点的个数仅需维护根节点size[find(x)]即可,但必须在两个集合合并之前, 为Q2查询操作做准备
            p[find(a)] = find(b); //将a作为子集插入到b集合中
        }
        else if (cmd[1] == '1') {//询问是否在一个连通块(集合)中
            scanf("%d %d", &a, &b);
            if (p[find(a)] == p[find(b)]) printf("Yes\n");
            else printf("No\n");
        }
        else if (cmd[1] == '2') { //询问连通块中点的个数
            scanf("%d", &a);
            printf("%d\n", s[find(a)]);
        }
    }

    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7523983/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。