#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
vector<PII> segs;

void merge(vector<PII>& q) {//区间合并
    vector<PII> res; //结果
    //第一步：设置初始区间
    int st = -2e9, ed = -2e9;//初始区间一定要设置成比题目要求范围还要小的区间以便第一个区间能成功成为维护区间
    //第二步：对所有区间段进行排序
    sort(q.begin(), q.end()); //sort会先比较item.first后比较item.second 按升序排序
    //第三步：逐个扫描区间并按情况更新维护的区间端点
    for (auto seg : q) {
        if (ed < seg.first) {//情况一：扫描的区间完全和维护区间无交集
            if (st != -2e9) res.push_back({ st , ed });
            st = seg.first, ed = seg.second;
        }
        else {//情况二：有交集情况下
            ed = ed > seg.second ? ed : seg.second; //更新右端点即可
        }
    }
    if (st != -2e9) res.push_back({ st , ed }); //将维护好的区间加入结果中(加上if防止出现空输入情况)

    q = res;
}

int main() {
    int n;
    cin >> n;
    //第一部分：数据输入部分
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({ l , r });
    }
    //第二部分：区间合并
    merge(segs);

    cout << segs.size() << endl;

    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7490867/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。