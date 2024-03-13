#include<iostream>
#include<cstring>
using namespace std;
const int N = 100002;
int n, m;
int d[N], q[N], h[N], e[N], ne[N], hh, tt, idx;

void init(void) {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    hh = tt = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}

int bfs(void) {
    d[1] = 0;
    q[0] = 1;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[n];
}
int main(void) {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}
