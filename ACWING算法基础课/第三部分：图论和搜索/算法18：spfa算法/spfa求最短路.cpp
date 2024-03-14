#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100086;
int h[N], e[N], ne[N], w[N], idx;
queue<int> q;
bool s[N];
int d[N];
int n, m;

void init(void) {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx, w[idx] = c, idx++;
}

int spfa(void) {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    q.push(1);
    s[1] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        s[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (!s[j]) {
                    q.push(j);
                    s[j] = true;
                }
            }
        }
    }
    return d[n];
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    int t = spfa();
    if (d[n] == 0x3f3f3f3f) printf("impossible");
    else printf("%d", d[n]);

    return 0;
}