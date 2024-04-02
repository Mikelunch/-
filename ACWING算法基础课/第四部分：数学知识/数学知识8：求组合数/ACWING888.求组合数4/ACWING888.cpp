#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 5002;

int primes[N], cnt = 0;
bool s[N];
int sum[N];//�洢��ǰ����p�� a/ b��ʱ�׳˵ĸ���
vector<int> ans;//�߾��ȳ˷�

void get_primes(int n) {//����ɸ��ȥ����
    for (int i = 2; i <= n; i++) {
        if (!s[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            s[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int get(int n, int p) {//�� ��n�Ľ׳��а���������p p^2 ....�ĸ���
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int>& q, int p) {
    vector<int> res;
    int t = 0;
    for (int i = 0; i < q.size(); i++) {
        t += q[i] * p;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        res.push_back(t % 10);
        t /= 10;
    }
    //while(res.back() == 0 && res.size() > 1) res.pop_back();//
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    get_primes(a);
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    ans.push_back(1);
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < sum[i]; j++) {
            ans = mul(ans, primes[i]);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}