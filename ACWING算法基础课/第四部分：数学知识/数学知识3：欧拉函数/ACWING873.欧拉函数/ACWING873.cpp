#include<iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        int res = num;
        for (int i = 2; i <= num / i; i++) {
            if (num % i == 0) {//i是质数
                res = res / i * (i - 1);
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1) res = res / num * (num - 1);//一定要考虑到还有num中最大的一个质数没有在循序中
        cout << res << endl;
    }
    return 0;
}