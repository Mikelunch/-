#include <iostream>
using namespace std;

const int N = 1e7;
int s[N], nums[N]; //在这里定义前缀和数组则不需要使用s0 = 0 操作

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]); //注意这里需要从1开始赋值
        s[i] = s[i - 1] + nums[i];//注意这里需要从1开始赋值
    }

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7479156/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。