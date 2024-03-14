#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100086;
int h[N], e[N], ne[N], w[N], idx;
queue<int> q;
bool s[N];
int d[N], cnt[N];
int n, m;

void init(void) {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx, w[idx] = c, idx++;
}

bool spfa(void) {
    for (int i = 1; i <= n; i++) {
        s[i] = true;
        q.push(i);
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();
        s[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!s[j]) {
                    q.push(j);
                    s[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    if (spfa()) printf("Yes");
    else printf("No");

    return 0;
}