#include<iostream>
#include<cstring>
#include<queue> //使用STL的堆实现
#include<algorithm>

using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10;//稠密图一般使用堆优化版算法 
int h[N], e[N], ne[N], w[N], idx; // 堆优化版下图的存储方式改为邻接表 w[]存储权重
int d[N];
bool s[N];
int n, m;

void init(void) {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx, w[idx] = c, idx++;
}

int dijkstra(void) {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap; //初始化为小根堆 存储已经找到的最短路径节点及其距离
    heap.push({ 0, 1 });//d[1] = 0

    while (heap.size()) {//堆非空下
        auto t = heap.top();//
        heap.pop();
        int dis = t.first, p = t.second;
        if (s[p]) continue;//
        s[p] = true;
        for (int i = h[p]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[p] + w[i]) {
                d[j] = d[p] + w[i];
                heap.push({ d[j] , j });
            }

        }
    }

    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        add(a, b, x);
    }
    //cout << dijkstra() << endl;
    printf("%d ", dijkstra());
    return 0;
}


