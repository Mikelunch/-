#include<iostream>
#include<cstring>
using namespace std;
const int N = 502, INF = 0x3f3f3f3f;
int g[N][N], d[N];
bool s[N];
int n, m;

int prim(void) {
    memset(d, 0x3f, sizeof d);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!s[j] && (t == -1 || d[j] < d[t])) {
                t = j;
            }
        }
        s[t] = true;
        if (i && d[t] == INF) return INF;
        if (i) res += d[t];
        for (int j = 1; j <= n; j++) {
            d[j] = d[j] < g[t][j] ? d[j] : g[t][j];
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = g[b][a] = g[a][b] < c ? g[a][b] : c;
    }
    int t = prim();
    if (t == INF) printf("impossible");
    else printf("%d", t);
    return 0;
}