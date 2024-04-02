#include<iostream>
using namespace std;

int exgcd(int a, int b, int& x, int& y) {//注意x , y是引用，要逐级递归出来 函数返回gcd(b , a % b);
    if (!b) {//即 ax = gcd(a , 1)的情况
        x = 1, y = 0;
        return 1;//应为函数返回的gcd(1 , a % 1);
    }
    int d = exgcd(b, a % b, y, x);//反转是为了好算 详见推导式
    y = y - a / b * x;//y需要更新而x不需要
    return d;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, x, y;
        scanf("%d %d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}