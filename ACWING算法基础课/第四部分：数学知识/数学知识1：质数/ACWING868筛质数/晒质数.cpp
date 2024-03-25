#include<iostream>
using namespace std;

const int N = 1000010;
int n;
bool s[N];//标记是否为质数
int primes[N];//存储质数
int cnt;//题目输出

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