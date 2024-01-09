#include<iostream>
#include<algorithm>
#include<cstring>

using namespace  std;

typedef pair<int, int> PII;
const int N = 101;
int d[N][N], g[N][N]; //d存储对应坐标到起始点的距离 g是迷宫数据
PII q[N * N];//存储坐标
int hh, tt, m, n;

void init() {//初始化各种参数
    hh = tt = 0;//先保证队列非空
    memset(d, -1, sizeof(d));//标记每个点都是未走过的状态
    d[0][0] = 0;//标记起始点是默认走过的状态
    for (int i = 0; i < n; i++)//输入迷宫数据
        for (int j = 0; j < m; j++) scanf("%d", &g[i][j]);
}

int bfs() {
    q[0] = { 0 , 0 };// 第一步：将初始状态插入队头
    int dx[4] = { 0 ,0 ,1 ,-1 }, dy[4] = { 1 , -1 ,0 ,0 };//用2个方向数组来代表四个前进方向 可参考ACWING765
    while (hh <= tt) { // 只要队列非空就一直进行
        auto t = q[hh++]; // 第二步：取出队头元素
        for (int i = 0; i < 4; i++) {//四个方向都要遍历一边以确定下一层所有可能的点
            int x = t.first + dx[i], y = t.second + dy[i];//四个方向遍历
            if (x >= 0 && x < n && y >= 0 && y < n && d[x][y] == -1 && g[x][y] == 0) {
                d[x][y] = d[t.first][t.second] + 1;//符合条件的点距离上一层的距离+1
                q[++tt] = { x , y };//存储符合条件的坐标
            }
        }
    }
    return d[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    init();
    cout << bfs() << endl;
    /* 展示距离用
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++) printf("%d ", d[i][j]);
        printf("\n");
    }
    */
    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7590755/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。