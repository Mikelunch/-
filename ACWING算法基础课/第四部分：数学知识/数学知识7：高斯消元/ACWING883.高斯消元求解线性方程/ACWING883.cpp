#include<iostream>
#include<cmath>
using namespace std;

const int N = 102;
const double eps = 1e-6;//浮点数比较接受误差范围
double a[N][N]; //系数矩阵
int n;


void out() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}

int gauss(void) {//实际上就是初等变换
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;//暂存绝对值最大数的行数
        for (int i = r; i < n; i++) {//寻找当前列中的最大行
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }
        if (fabs(a[t][c]) < eps) continue;//如果当前最大数为0，说明该行是全0列，换列
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);//交换该行和当前的阶梯行
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];//将阶梯的一个数变为1
        for (int i = r + 1; i < n; i++) {//将当前阶梯行下面对应的系数肖为0
            if (fabs(a[i][c]) > eps) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];//将r行以下行的第c列数肖为0
                }
            }
        }
        out();
        printf("\n");
        r++;
    }
    if (r < n) {//无解或者无穷多解
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps)
                return 2;//无解
        }
        return 1;//无穷多解
    }

    for (int i = n - 1; i >= 0; i--) {//用得到的阶梯阵反解出唯一解
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 0;//唯一解
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {//输入增广矩阵
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    int t = gauss();//高斯消元求解
    if (t == 0) {
        for (int i = 0; i < n; i++) printf("%.2f\n", a[i][n]);//输出最后一列即为唯一解
    }
    else if (t == 1) printf("Infinite group solutions\n");
    else printf("No solution\n");
    return 0;
}
