#include<iostream>
#include<queue>
using namespace std;
const int N = 1e5 + 10, M = N << 1;
int n;
struct Ranges {
    int l, r;
}ranges[N];

int heap[M], idx = 0;//数组模拟堆

void down(int x) {
    int t = x;
    if (x * 2 <= idx && heap[x] > heap[x * 2]) t = x * 2;
    if (x * 2 + 1 <= idx && heap[t] > heap[x * 2 + 1]) t = x * 2 + 1;
    if (t != x) {
        swap(heap[t], heap[x]);
        down(t);
    }
}

void up(int x) {
    while (x / 2 && heap[x] < heap[x / 2]) {
        swap(heap[x], heap[x / 2]);
        x /= 2;
    }
}

void merge_sort(Ranges ranges[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(ranges, l, mid), merge_sort(ranges, mid + 1, r);
    int i = l, j = mid + 1, t = 0;
    Ranges k[r - l + 1];
    while (i <= mid && j <= r) {
        if (ranges[i].l < ranges[j].l) k[t++] = ranges[i++];
        else k[t++] = ranges[j++];
    }
    while (i <= mid) k[t++] = ranges[i++];
    while (j <= r) k[t++] = ranges[j++];
    for (i = l, j = 0; i <= r; i++, j++) ranges[i] = { k[j].l , k[j].r };
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        ranges[i] = { l , r };
    }
    merge_sort(ranges, 0, n - 1);
    int isempty = 0;
    for (int i = 0; i < n; i++) {
        auto range = ranges[i];
        if (!idx || heap[1] >= range.l) {
            heap[++idx] = range.r; //加入堆中
            up(idx), down(idx);
        }
        else {
            heap[1] = range.r;//将堆顶值进行更新并重置堆
            up(1), down(1);
        }

    }
    cout << idx << endl;
    return 0;
}