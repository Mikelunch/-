#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

typedef long long LL;
const int M = 1e9 + 7;
unordered_map<int, int> primes;//用于存储质数及其指数

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {//说明可以进行质数为i的分解
                x /= i;
                primes[i]++;//质数对应的指数++
            }
        }
        if (x > 1) primes[x]++;//x < i时 将 x % i == 0剩下的最大大质数加入
    }

    LL res = 1;
    for (auto prime : primes) res = res * (prime.second + 1) % M;
    printf("%d", res);
    return 0;
}