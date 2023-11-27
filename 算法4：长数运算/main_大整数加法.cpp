#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int>& p, vector<int>& q) { //使用引用更快 不使用的话其会先复制一个vecotor在操作
    vector<int> c;
    int t = 0;
    for (int i = 0; i < p.size() || i < q.size(); i++) {
        if (i < p.size()) t += p[i]; //一定要考虑当前位是否存在
        if (i < q.size()) t += q[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t); //如果最高位也有进位的情况
    return c;
}

int main() {
    string a, b;
    vector<int> num1, num2;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) num1.push_back(a[i] - '0');//insert(num1.begin(),a[i] - '0')更优雅但超时
    for (int i = b.size() - 1; i >= 0; i--) num2.push_back(b[i] - '0');

    auto c = add(num1, num2);

    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    return 0;
}

//作者：ConstantZ
//链接：https ://www.acwing.com/activity/content/code/content/7434688/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。