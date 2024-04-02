#include<iostream>
using namespace std;

typedef long long LL;
const int N = 100086, mod = 1e9 + 7;
int fact[N], infact[N]; //�׳� �� ��Ԫ�Ľ׳�
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
    fact[0] = 1, infact[0] = 1;//Ĭ��0�Ľ׳˺���Ԫ�׳�ҪԤ����
    for (int i = 1; i < N; i++) {//Ԥ������׳˺ͽ׳˵���Ԫ
        fact[i] = (LL)fact[i - 1] * i % mod;//ע�⣬ �׳˵Ŀ��ܷǳ�������ǿת������ȡ�������������Ԥ����ȡ��
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;//����������Ԫ
    }
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod); //��ǰmod��ֹ���
    }
    return 0;
}