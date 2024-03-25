#include<iostream>
using namespace std;

const int N = 1000010;
int n;
bool s[N];//����Ƿ�Ϊ����
int primes[N];//�洢����
int cnt;//��Ŀ���

void get_prime(int q) {
    for (int i = 2; i <= q; i++) {
        if (!s[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= q / i; j++) {
            s[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;
    get_prime(n);
    printf("%d", cnt);
    return 0;
}