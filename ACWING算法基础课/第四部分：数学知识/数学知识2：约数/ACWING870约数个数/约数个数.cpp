#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

typedef long long LL;
const int M = 1e9 + 7;
unordered_map<int, int> primes;//���ڴ洢��������ָ��

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {//˵�����Խ�������Ϊi�ķֽ�
                x /= i;
                primes[i]++;//������Ӧ��ָ��++
            }
        }
        if (x > 1) primes[x]++;//x < iʱ �� x % i == 0ʣ�µ�������������
    }

    LL res = 1;
    for (auto prime : primes) res = res * (prime.second + 1) % M;
    printf("%d", res);
    return 0;
}