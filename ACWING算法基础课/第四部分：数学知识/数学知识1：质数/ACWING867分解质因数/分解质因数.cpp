#include<iostream>
using namespace std;
int n;

void divide(int q) {
    for (int i = 2; i <= q / i; i++) {
        if (q % i == 0) {
            int s = 0;
            while (q % i == 0) {
                q /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (q > 1) printf("%d %d\n", q, 1);
    printf("\n");
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        divide(num);
    }
    return 0;
}