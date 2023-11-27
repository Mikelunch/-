#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> div(vector<int>& q, int p, int& r) { //定于 q / b 商为res 余数为r
    vector<int> res;
    int t = 0; //除法数据暂存位
    for (int i = q.size() - 1; i >= 0; i--) {
        t = t * 10 + q[i];
        res.push_back(t / p);
        t %= p;
    }
    reverse(res.begin(), res.end());//除法的需要将首位倒置 做到和 + - *运算一样的数据存储格式
    r = t; //余数就是最后一次的t值

    while (res.size() > 1 && res.back() == 0) res.pop_back(); //去除前导0
    return res; //返回商
}

int main() {
    string a;
    int b;
    int yushu;
    vector<int> nums;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) nums.push_back(a[i] - '0');

    auto c = div(nums, b, yushu);

    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    printf("\n%d", yushu);

    return 0;
}

//作者：ConstantZ
//链接：https ://www.acwing.com/activity/content/code/content/7435945/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。