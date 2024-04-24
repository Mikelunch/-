#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 100002;
int nums[N];
LL res = 0;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    int mid = nums[n / 2];
    for (int i = 0; i < n; i++) res += abs(nums[i] - mid);
    cout << res << endl;
    return 0;
}