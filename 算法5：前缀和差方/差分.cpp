#include <iostream>
using namespace std;

const int N = 1e7;
int a[N], b[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) { //根据前缀和数组a构造a的差方数组b
        b[i] += a[i];      //这里可以理解为b一开始是0 a数组的构造其实是在b的当前位置进行插入操作
        b[i + 1] -= a[i];
    }

    while (m--) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        b[l] += c; //根据差分和的性质可以得出：前缀和某一段上的加法操作可以由差分数组完成
        b[r + 1] -= c;
    }

    for (int i = 1; i <= n; i++) b[i] += b[i - 1]; //使得差分转换为前缀和输出

    for (int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}