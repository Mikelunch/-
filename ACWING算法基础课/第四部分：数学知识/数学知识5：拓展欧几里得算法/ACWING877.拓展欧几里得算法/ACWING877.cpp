#include<iostream>
using namespace std;

int exgcd(int a, int b, int& x, int& y) {//ע��x , y�����ã�Ҫ�𼶵ݹ���� ��������gcd(b , a % b);
    if (!b) {//�� ax = gcd(a , 1)�����
        x = 1, y = 0;
        return 1;//ӦΪ�������ص�gcd(1 , a % 1);
    }
    int d = exgcd(b, a % b, y, x);//��ת��Ϊ�˺��� ����Ƶ�ʽ
    y = y - a / b * x;//y��Ҫ���¶�x����Ҫ
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