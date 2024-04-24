#include<iostream>
using namespace std;
const int N = 1e5 + 10;
struct Ranges {
    int l, r;
}ranges[N];
int n, st, ed;

void quick_sort(Ranges ranges[], int l, int r) {
    if (l >= r) return;
    int mid_point = ranges[(l + r) >> 1].l;
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (ranges[i].l < mid_point);
        do j--; while (ranges[j].l > mid_point);
        if (i < j) {
            swap(ranges[i], ranges[j]);
        }
    }
    quick_sort(ranges, l, j), quick_sort(ranges, j + 1, r);
}

int main() {
    cin >> st >> ed;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        ranges[i] = { l , r };
    }
    quick_sort(ranges, 0, n - 1);
    int ans = 0;
    bool is_success = false;
    for (int i = 0; i < n; i++) {
        int j = i, r = -2e9;
        while (j < n && ranges[j].l <= st) {
            r = max(r, ranges[j].r);
            j++;
        }
        if (r < st) {
            ans = -1;
            break;
        }
        ans++;
        if (r >= ed) {
            is_success = true;
            break;
        }
        st = r;
        i = j - 1;
    }
    if (is_success) cout << ans << endl;
    else cout << "-1 " << endl;
    return 0;
}