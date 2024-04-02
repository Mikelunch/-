#include<iostream>
using namespace std;
const int N = 100002;
typedef long long LL;

int n;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {//实际上就是处理k的二进制位
        if (k & 1) res = (LL)res * a % p;//大数相乘容易溢出，所以先转换为LL，或者直接全部定义为LL
        k >>= 1;//为k的下一位二进制做准备a
        a = (LL)a * a % p;//这里a如何很大的话相乘容易溢出 无论k是否为1，a均要为下一次做准备
    }
    return res;
}

int main() {
    cin >> n;
    while (n--) {
        int a, p;//准备提取的快速幂信息
        scanf("%d %d", &a, &p);
        int res = qmi(a, p - 2, p);
        if (a % p) printf("%d\n", res);
        else printf("impossible\n");
    }
    return 0;
}