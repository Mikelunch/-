#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0; //��0��ʼ����Ϊ�κ������0������������������������ʱ��γ�ʼ���ɵ�һ����
    while (n--) {
        int m;
        scanf("%d", &m);
        res ^= m;
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}