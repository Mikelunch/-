#include <iostream>
#include <vector>

using namespace std;

//判断2数绝对值下大小
bool cheakAbsNums(vector<int>& q, vector<int>& p) {
    if (q.size() != p.size()) return q.size() > p.size();
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] != p[i]) return q[i] > p[i];
    }
    return true; //两个数完全相同
}

vector<int> subBignums(vector<int>& q, vector<int>& p) {
    vector<int> c;//存放结果
    for (int i = 0, t = 0; i <= q.size() - 1; i++) { //从低到高 逐位相减
        t = q[i] - t; //当前位在被低位借位后的情况
        if (i < p.size()) t -= p[i];
        c.push_back((t + 10) % 10); //可以综合2中情况 即小于0 和大于等于0的情况
        if (t < 0) t = 1; //说明该位存在想高位借位的情况
        else t = 0;
    }
    //消除不必要的零使得答案正确
    while (c.size() > 1 && c.back() == 0) c.pop_back(); //将多余0的清楚

    return c;
}

int main() {
    string a, b;
    vector<int> num1, num2;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) num1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) num2.push_back(b[i] - '0');

    //第一步先判断2数绝对值下的大小
    vector<int> c;
    if (cheakAbsNums(num1, num2)) c = subBignums(num1, num2);
    else {
        printf("-");
        c = subBignums(num2, num1);
    }

    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);

    return 0;

}

//作者：ConstantZ
//链接：https ://www.acwing.com/activity/content/code/content/7434980/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。