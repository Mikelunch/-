#include<iostream>
#include<cstring>
using namespace std;

const int N = 520, M = 100086;
int h[N], e[M], ne[M], idx = 0;//邻接表存储
int match[N];//match[j] = i,表示n1中的i点匹配到n2中的j点
bool st[N];//本轮匹配时n2中点是否已经匹配
int n1, n2, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {//为n1中的x寻找n2中的配对点
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {//未配对或者已经配对的该点可以配对其他点
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {//步骤1：遍历n1中的所有点
        memset(st, false, sizeof st);//每次寻找点必须重置s[]确保该次匹配中能寻找到n2的所有点
        if (find(i)) {
            res++;
        }
    }
    printf("%d", res);
    return 0;
}