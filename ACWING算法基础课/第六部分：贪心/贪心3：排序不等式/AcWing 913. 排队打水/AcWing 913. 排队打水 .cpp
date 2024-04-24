#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int nums[N];
int n;

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, t = 0;
    int k[r - l + 1];
    while (i <= mid && j <= r) {
        if (q[i] < q[j]) k[t++] = q[i++];
        else k[t++] = q[j++];
    }
    while (i <= mid) k[t++] = q[i++];
    while (j <= r) k[t++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)q[i] = k[j];
}

int main() {
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    //sort(nums , nums + n);
    merge_sort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        ans += nums[i] * (n - i - 1);
    }
    cout << ans << endl;
    return 0;
}