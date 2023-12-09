#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int>  PII; //存放输入的数字 由于一次是输入一对数据 所以使用pair

const int N = 3e7; // 离散化过后最多只有 n + 2m个数组下标
int n, m;
int a[N], s[N]; // a[N]离散化后对应坐标的值 s[N]为a[N]的前缀和

vector<int> alls;//离散化后的数组下标 和a配套 及 alls的下标对用a里面的值
vector<PII> add, quiry; //插入操作和 求值操作

int find(int x) { //输入坐标x 输出离散化后在alls中的对应位置(下标) 二分法
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (alls[mid] <= x) l = mid; //找到x在alls数组中的位置
        else r = mid - 1;
    }
    return r + 1; //映射成自然数组 1 2 3 ...
}

void merge_sort(vector<int>& q, int l, int r) { //使用归并排序
    if (l >= r) return;
    int mid_point = (l + r) >> 1;

    merge_sort(q, l, mid_point), merge_sort(q, mid_point + 1, r);

    int i = l, j = mid_point + 1, k = 0;
    int temp[r + 1 - l];
    while (i <= mid_point && j <= r) {
        if (q[i] < q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    }
    while (i <= mid_point) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];

}

vector<int> ::iterator unique(vector<int>& q) { //补充内容：手写去重
    int j = 0;
    for (int i = 0; i < q.size(); i++)
        if (!i || q[i] != q[i - 1])//有序数列去重核心：存储第一个和前后2个不相同的数
            q[j++] = q[i];
    return q.begin() + j;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) { //读入插入的值
        int x, c; //x为插入的下标 c为插入的值
        cin >> x >> c;
        add.push_back({ x , c });

        alls.push_back(x); //将坐标加入到离散化后的数组
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        quiry.push_back({ l , r });

        alls.push_back(l);
        alls.push_back(r); //将所有需要用到的下标加入到离散化数组中
    }

    //离散化第一步：排序
    //sort(alls.begin(), alls.end());
    merge_sort(alls, 0, alls.size() - 1);
    //for(auto item : alls) cout << item << " ";

    //离散化第二步：去重
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //处理插入
    for (auto item : add) {
        int x = find(item.first);//坐标离散化
        a[x] += item.second; //在离散化数组下加上对应插入的值
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    //处理询问
    for (auto item : quiry) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}