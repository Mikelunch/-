#include<iostream>
#include<cstring>
using namespace std;
const int N = 100086, M = 2 * N; //无向图注意2倍
int h[N], e[M], ne[M], idx = 0;//邻接表形式存储
int color[N];//染色点 0:未染色 1:染色成1 2:染色成2 ， 不存在0 1 2之外其他值
int n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int t, int c) {//t:要染色的顶点 c:染色1 / 2
    color[t] = c;
    for (int i = h[t]; ~i; i = ne[i]) {//利用邻接表配合dfs将t为顶点的向周围所有的点(连通块)进行染色或者判断
        int j = e[i];
        if (!color[j]) {//没有染色就染色
            if (!dfs(j, 3 - c)) return false; //该点染成区别于上一层点的色
        }
        else if (color[j] != 3 - c) return false;//该点已经染色但值同上一层点的值一样，说明是图中含有奇数环，不是二分图
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b), add(b, a);//无向图即有向图的双向添加
    }
    bool flag = true;//结果输出 真：该图是二分图。 假：改图不是二分图
    for (int i = 1; i <= n; i++) { //第一步：遍历所有点
        if (!color[i])//没有染色就染色 
            if (!dfs(i, 1)) {//染色 1 2 均可以 染色失败
                flag = false;
                break;
            }
    }
    if (flag) printf("Yes");
    else printf("No");
    return 0;
}

