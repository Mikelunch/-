#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;

typedef long long LL;
int primes[N], cnt;
bool s[N];
int n;
LL euler[N];

int main() {
    cin >> n;
    euler[1] = 1;//注意特殊处理
    LL res = 0;
    for (int i = 2; i <= n; i++) {
        if (!s[i]) {
            primes[cnt++] = i;
            euler[i] = i - 1;//一个数是质数情况下，它的欧拉函数值
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            s[t] = true;
            if (i % primes[j] == 0) {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1); //i % primes != 0的情况
        }
    }
    for (int i = 1; i <= n; i++) res += euler[i];
    cout << res << endl;
    return 0;
}