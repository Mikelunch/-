#include<iostream>
using namespace std;

const int N = 101;
int n;

bool is_prime(int q) {
    if (q < 2) return false;
    bool flag = true;
    for (int i = 2; i <= q / i; i++) {
        if (q % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}


int main() {
    cin >> n;
    while (n--) {
        int num;
        scanf("%d", &num);
        if (is_prime(num)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}