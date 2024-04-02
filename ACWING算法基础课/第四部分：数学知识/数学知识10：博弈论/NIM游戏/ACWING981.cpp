#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0; //以0开始是因为任何数异或0还是它本身，接下来输入数据时便课初始化成第一个数
    while (n--) {
        int m;
        scanf("%d", &m);
        res ^= m;
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}