#include<iostream>
using namespace std;
typedef long long LL;
const int N = 20;
int n, m;
int p[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) scanf("%d", &p[i]);//读入m个质数
    int res = 0;
    for (int i = 1; i < 1 << m; i++) { //由容斥定理得一共要处理 2^m - 1个集合数据
        int t = 1, cnt = 0;//t表示集合质数乘积，cnt表示集合数
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {//i的第j位上为1,表示该集合便选择
                if ((LL)t * p[j] > n) {//乘积超过范围，表明不在范围内
                    t = -1;
                    break;
                }
                t *= p[j];
                cnt++;
            }

        }
        if (t != -1) {
            if (cnt % 2) res += n / t;//偶减奇加
            else res -= n / t;
        }
    }
    cout << res << endl;
    return 0;
}