#include<iostream>
using namespace std;
const int N = 100002;
typedef long long LL;

int n;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {//ʵ���Ͼ��Ǵ���k�Ķ�����λ
        if (k & 1) res = (LL)res * a % p;//����������������������ת��ΪLL������ֱ��ȫ������ΪLL
        k >>= 1;//Ϊk����һλ��������׼��a
        a = (LL)a * a % p;//����a��κܴ�Ļ����������� ����k�Ƿ�Ϊ1��a��ҪΪ��һ����׼��
    }
    return res;
}

int main() {
    cin >> n;
    while (n--) {
        int a, p;//׼����ȡ�Ŀ�������Ϣ
        scanf("%d %d", &a, &p);
        int res = qmi(a, p - 2, p);
        if (a % p) printf("%d\n", res);
        else printf("impossible\n");
    }
    return 0;
}