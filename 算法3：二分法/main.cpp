#include <iostream>

using namespace std;

const int N = 100000;
int nums[N];

int main() {
    int n, q;
    int l_bound, r_bound;
    cin >> n >> q;
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    while (q--) {
        int num;
        cin >> num;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1; //第一步确定当前二分点
            if (nums[mid] <= num) l = mid;
            else r = mid - 1;
        }
        if (nums[l] != num) {
            cout << "-1 -1" << endl;
            continue;
        }
        else {
            r_bound = r;
            l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (nums[mid] >= num) r = mid;
                else l = mid + 1;
            }
            l_bound = l;
        }
        cout << l_bound << " " << r_bound << endl;
    }
    return 0;
}