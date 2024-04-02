#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, m, x, y;
        scanf("%d %d %d", &a, &b, &m);
        int d = exgcd(a, m, x, y);
        if (b % d) puts("impossible");
        else printf("%d\n", (LL)x * (b / d) % m);
        //else printf("%d\n" ,(m * y + b) / a);
    }
    return 0;
}