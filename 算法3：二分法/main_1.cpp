#include <iostream>
#include <cmath>
using namespace std;

#define slope 1e-8

int main() {
    double num;
    cin >> num;
    int cnt = 0;
    double l, r;
    if (num >= 0) l = 0, r = num * 10000; //防止有绝对值小于1的数进行立方根而超范围 如0.001的立方根是0.1 而0.1不在0，0001的范围内
    else l = num * 10000, r = 0;

    while (r - l > slope) {
        double mid = (l + r) / 2;
        if (pow(mid, 3) >= num) r = mid;
        else l = mid;
    }

    printf("%6f", r);

    return 0;
}