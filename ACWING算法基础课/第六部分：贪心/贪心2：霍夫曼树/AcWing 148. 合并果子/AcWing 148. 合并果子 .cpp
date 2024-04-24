#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10002, M = N << 1;
int n;
int w[N];
int heap[M], idx = 0;

void down(int x) {
    int t = x;
    if (x * 2 <= idx && heap[x] > heap[x * 2]) t = x * 2;
    if (x * 2 + 1 <= idx && heap[t] > heap[x * 2 + 1]) t = x * 2 + 1;
    if (t != x) {
        swap(heap[x], heap[t]);
        down(t);
    }
}

void up(int x) {
    while (x / 2 && heap[x] < heap[x / 2]) {
        swap(heap[x], heap[x / 2]);
        x /= 2;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        heap[++idx] = w;//压入小根堆中
        down(idx), up(idx);
    }
    int ans = 0;
    while (idx > 1) {
        int x = heap[1];//剔除栈顶
        heap[1] = heap[idx];
        idx--;
        down(1), up(1);
        int y = heap[1];
        heap[1] = heap[idx];
        idx--;
        down(1), up(1);
        int res = x + y;
        ans += res;
        heap[++idx] = res;//最后的结果要压入堆中
        down(idx), up(idx);
    }
    cout << ans << endl;
    return 0;
}