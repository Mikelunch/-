#include<iostream>
#include<cmath>
using namespace std;

const int N = 102;
const double eps = 1e-6;//�������ȽϽ�����Χ
double a[N][N]; //ϵ������
int n;


void out() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}

int gauss(void) {//ʵ���Ͼ��ǳ��ȱ任
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;//�ݴ����ֵ�����������
        for (int i = r; i < n; i++) {//Ѱ�ҵ�ǰ���е������
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }
        if (fabs(a[t][c]) < eps) continue;//�����ǰ�����Ϊ0��˵��������ȫ0�У�����
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);//�������к͵�ǰ�Ľ�����
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];//�����ݵ�һ������Ϊ1
        for (int i = r + 1; i < n; i++) {//����ǰ�����������Ӧ��ϵ��ФΪ0
            if (fabs(a[i][c]) > eps) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];//��r�������еĵ�c����ФΪ0
                }
            }
        }
        out();
        printf("\n");
        r++;
    }
    if (r < n) {//�޽����������
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps)
                return 2;//�޽�
        }
        return 1;//������
    }

    for (int i = n - 1; i >= 0; i--) {//�õõ��Ľ����󷴽��Ψһ��
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 0;//Ψһ��
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {//�����������
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    int t = gauss();//��˹��Ԫ���
    if (t == 0) {
        for (int i = 0; i < n; i++) printf("%.2f\n", a[i][n]);//������һ�м�ΪΨһ��
    }
    else if (t == 1) printf("Infinite group solutions\n");
    else printf("No solution\n");
    return 0;
}
