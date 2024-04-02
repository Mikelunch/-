#include<iostream>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7, N = 200016;
int n;
int fact[N], infact[N];

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
    int a = n * 2, b = n;
    //b < a < 1e6 ���ݷ�Χ��Ԥ����Χ��
    fact[0] = 1, infact[0] = 1;
    //����Ԥ�����1 ~ 2n�ĵݹ���Ԫ�͵ݹ�
    for (int i = 1; i <= a; i++) fact[i] = (LL)fact[i - 1] * i % mod;
    for (int i = 1; i <= b + 1; i++) infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    int res = 1;
    //��ֹ��intһ����һ����������ȡ��
    res = (LL)res * fact[a] % mod;
    res = (LL)res * infact[a - b] % mod;
    res = (LL)res * infact[b] % mod;
    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;
    cout << res << endl;
    return 0;
}