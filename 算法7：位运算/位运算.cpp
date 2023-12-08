#include <iostream>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int n, num;
    cin >> n;
    while (n--) {
        //cin >> num;
        scanf("%d", &num);
        int res = 0;
        while (num) num -= lowbit(num), res++; //核心 每次去掉对后一位1即可
        //cout << res << " ";
        printf("%d ", res);
    }

    return 0;
}
