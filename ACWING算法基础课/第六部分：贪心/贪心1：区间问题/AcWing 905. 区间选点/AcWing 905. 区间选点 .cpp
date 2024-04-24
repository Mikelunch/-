#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n;
struct Ranges {
    int l, r;
}ranges[N];

void quick_sort(Ranges ranges[], int l, int r) {
    if (l >= r) return;
    int mid = ranges[(l + r) >> 1].r;
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (ranges[i].r < mid);
        do j--; while (ranges[j].r > mid);
        if (i < j) {
            swap(ranges[i].r, ranges[j].r);
            swap(ranges[i].l, ranges[j].l);
        }
    }
    quick_sort(ranges, l, j), quick_sort(ranges, j + 1, r);

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        ranges[i] = { l , r };
    }
    quick_sort(ranges, 0, n - 1);
    int res = 0, min_r = -2e9;
    for (int i = 0; i < n; i++) {
        auto range = ranges[i];
        if (range.l > min_r) {
            res++;
            min_r = range.r;
        }

    }
    cout << res << endl;
    return 0;
}