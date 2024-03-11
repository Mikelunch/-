#include<iostream>
#include<cstring>
using namespace std;
const int N = 502;
int n, m;
int g[N][N];//邻接矩阵 存储的是权重值
int d[N];//每个点到起点的最短距离
bool st[N];//每个点的最短路是否已经确定

int dijkstra(void) {
    memset(d, 0x3f3f3f3f, sizeof d);
    d[1] = 0; //第一步 初始化各点的距离 除起点外均为最大值
    for (int i = 1; i <= n; i++) {//第二步：遍历节点
        int t = -1;//当前节点还在待定
        for (int j = 1; j <= n; j++) {//寻找不在st[]中的距离最近的点
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        }
        st[t] = true;//加入到已发现的最短路节点中去
        for (int j = 1; j <= n; j++) {//第三步：用t去更新其他点 为什么不用管这两点时候连接？ 因为初始化距离是是按最大值初始化的
            if (d[j] > d[t] + g[t][j])
                d[j] = d[t] + g[t][j];
        }
    }
    if (d[n] == 0x3f3f3f3f) return -1;//说明起点到n点不互通
    return d[n];
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f3f, sizeof g);
    while (m--) {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        g[a][b] = g[a][b] > x ? x : g[a][b]; //重边情况下进保留距离最短的一条边 自环亦然
    }
    cout << dijkstra() << endl;
    return 0;
}