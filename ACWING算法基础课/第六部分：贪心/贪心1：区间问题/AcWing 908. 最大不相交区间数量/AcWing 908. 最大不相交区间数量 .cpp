#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;

int n;
struct Ranges {
    int l, r;
    bool operator < (const Ranges& M)const {//���������Ҷ˵��С��������
        return r < M.r;
    }
}ranges[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        ranges[i] = { l , r };
    }
    sort(ranges, ranges + n);//�����Ҷϵ�����
    int st = -2e9, ed = -2e9; //��ǰ�������Ҷ˵�
    int res = 0;//��
    for (int i = 0; i < n; i++) {
        if (ranges[i].l > ed) { //���µ������� ֮ǰ�н��ʵ�������Ҷ˵� < ��ǰ�������˵�
            res++;
            ed = ranges[i].r;
        }
    }
    cout << res << endl;
    return 0;
}