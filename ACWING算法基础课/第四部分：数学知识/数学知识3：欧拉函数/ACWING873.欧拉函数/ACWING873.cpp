#include<iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        int res = num;
        for (int i = 2; i <= num / i; i++) {
            if (num % i == 0) {//i������
                res = res / i * (i - 1);
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1) res = res / num * (num - 1);//һ��Ҫ���ǵ�����num������һ������û����ѭ����
        cout << res << endl;
    }
    return 0;
}