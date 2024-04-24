#include<iostream>
using namespace std;
typedef long long LL;
const int N = 50002;
struct Bells {
    int w, s;
}bells[N];
int n;

void quick_sort(Bells b[], int l, int r) {
    if (l >= r) return;
    int mid_point = b[(l + r) >> 1].w + b[(l + r) >> 1].s;
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (b[i].s + b[i].w < mid_point);
        do j--; while (b[j].s + b[j].w > mid_point);
        if (i < j) swap(b[i], b[j]);
    }
    quick_sort(b, l, j), quick_sort(b, j + 1, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w, s;
        scanf("%d %d", &w, &s);
        bells[i] = { w , s };
    }
    quick_sort(bells, 1, n);
    int ans = -2e9;
    LL total_w = 0;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        total_w += bells[i - 1].w;
        res = total_w - bells[i].s;
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}