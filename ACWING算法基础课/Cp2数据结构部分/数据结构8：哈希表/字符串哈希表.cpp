#include<iostream>
using namespace std;
typedef unsigned long long ULL;

const int N = 100010;
char str[N];//Input String
ULL h[N], s[N];//hash code for each substring and s[i] corresponds to the decimal number at bit i
int p = 131;//experience value for string to it's hash code

ULL find(int l, int r) {//find string r ~ l's hash code
    return h[r] - h[l - 1] * s[r - l + 1];//This is introduced by the formula. Note that the strings 
    //R~L should have their hash subscripts h[r]~h[l-1]
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", str + 1);//attention: we start to stroe string at bit 1

    s[0] = 1;//attention: s[0] must init at first
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * p;//
        h[i] = h[i - 1] * p + str[i];//because the first char str[1] is the heighest char and str[i] is the loweset char
    }
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (find(l1, r1) == find(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}