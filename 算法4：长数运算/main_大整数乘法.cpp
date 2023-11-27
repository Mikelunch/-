#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& q, int p) {
    vector<int> res;
    int t = 0; //进位暂存变量
    for (int i = 0; i < q.size() || t; i++) { //这里加上 t判断是为了最高位能顺利写入vector中 也可以循环结束后在加上在高位（同加法部分的算法一样）
        if (i < q.size()) t += q[i] * p; //当前位的运算
        res.push_back(t % 10); //当前数位的数
        t /= 10; //暂存下一位进位
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back(); //清除前导0

    return res;
}
int main() {
    string a;
    int b;
    vector<int> A;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;

}

//作者：ConstantZ
//链接：https ://www.acwing.com/activity/content/code/content/7435771/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。