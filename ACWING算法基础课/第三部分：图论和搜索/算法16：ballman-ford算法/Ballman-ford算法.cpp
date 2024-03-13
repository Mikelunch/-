#include<iostream>
#include<cstring>
using namespace std;
const int N = 503, M = 10003;
int n, m, k;
int d[N], bakcup[N];
struct Edge {
    int a, b, w;
}edges[M];

int bellman_ford(void) {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 0; i < k; i++) {//因为题目中要求是最多经过k条边的1-n的最短距离，所以外层循环迭代k次
        memcpy(bakcup, d, sizeof d);//存储上一次的数据，以防本次更新距离时串联数据
        for (int j = 0; j < m; j++) {//遍历每一条边的距离，并更新
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            d[b] = d[b] < bakcup[a] + w ? d[b] : bakcup[a] + w;//更新成更短的距离 注意要用之前跟新的数据距离去更新当前的距离
            printf("d[%d] = %d ", b, d[b]);
        }
        printf("\n");
    }
    if (d[n] > 0x3f3f3f3f / 2) return -1; //可能存在负权边情况，导致最后的结果比0x3f3f3f3f小，但仍无法从1到n
    return d[n];//需要注意的是d[n] 可能等于-1，此时需要加上d[n] != -1才能判断是否无法从1到n
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges[i] = { a , b , w };
    }
    int t = bellman_ford();
    if (t == -1 && d[n] != -1) printf("impossible");
    else printf("%d", t);
    return 0;
}
