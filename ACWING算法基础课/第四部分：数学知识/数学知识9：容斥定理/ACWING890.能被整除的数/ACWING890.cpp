#include<iostream>
using namespace std;
typedef long long LL;
const int N = 20;
int n, m;
int p[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) scanf("%d", &p[i]);//����m������
    int res = 0;
    for (int i = 1; i < 1 << m; i++) { //���ݳⶨ���һ��Ҫ���� 2^m - 1����������
        int t = 1, cnt = 0;//t��ʾ���������˻���cnt��ʾ������
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {//i�ĵ�jλ��Ϊ1,��ʾ�ü��ϱ�ѡ��
                if ((LL)t * p[j] > n) {//�˻�������Χ���������ڷ�Χ��
                    t = -1;
                    break;
                }
                t *= p[j];
                cnt++;
            }

        }
        if (t != -1) {
            if (cnt % 2) res += n / t;//ż�����
            else res -= n / t;
        }
    }
    cout << res << endl;
    return 0;
}