#include<iostream>
using namespace std;

typedef long long LL;
int p, n;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = (LL)res * a % p;
        }
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int C(int a, int b, int p) {//求组合数
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % p;//组合数分子部分
        res = (LL)res * qmi(i, p - 2, p) % p;//利用快速幂求逆元从而将分母部分转换从乘法
    }
    return res;
}


int lucas(LL a, LL b, int p) {
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;//建议第二项不要直接用C,容易爆int,可以用lucas递归求
}

int main() {
    cin >> n;
    while (n--) {
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}