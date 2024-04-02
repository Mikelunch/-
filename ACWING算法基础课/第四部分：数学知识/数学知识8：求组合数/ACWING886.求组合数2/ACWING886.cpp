#include<iostream>
using namespace std;

typedef long long LL;
const int N = 100086, mod = 1e9 + 7;
int fact[N], infact[N]; //阶乘 和 逆元的阶乘
int n;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main() {
    cin >> n;
    fact[0] = 1, infact[0] = 1;//默认0的阶乘和逆元阶乘要预处理
    for (int i = 1; i < N; i++) {//预处理求阶乘和阶乘的逆元
        fact[i] = (LL)fact[i - 1] * i % mod;//注意， 阶乘的可能非常大，所以强转后利用取余运算的性质先预处理取余
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;//快速幂求逆元
    }
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod); //提前mod防止溢出
    }
    return 0;
}