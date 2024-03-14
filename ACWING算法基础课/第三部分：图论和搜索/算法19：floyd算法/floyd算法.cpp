#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 205, INF = 1e9;
int d[N][N];//邻接矩阵存储 多次遍历所有边
int n, m, k;

void floyd(void) {
    for (int i = 1; i <= n; i++) { //中继点一定要放在外环
        for (int j = 1; j <= n; j++) {//起始点放在第二重循环
            for (int k = 1; k <= n; k++) {//终止点放在最里面的循环
                //d[j][k] = d[j][k] < (d[j][i] + d[i][k]) ? d[j][k] : (d[j][i] + d[i][k]);
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);//想象成向量的加法
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) //删去自环的情况
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = d[a][b] < c ? d[a][b] : c; //删除重边的情况
    }

    floyd();

    while (k--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int t = d[x][y];
        if (t > INF / 2) printf("impossible\n");
        else printf("%d\n", t);
    }

    return 0;
}