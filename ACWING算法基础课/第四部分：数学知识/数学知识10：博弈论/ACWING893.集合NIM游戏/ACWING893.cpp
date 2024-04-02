#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<cstring>
using namespace std;
const int N = 110, M = 10086;//石头堆数 每堆石子数
int n, m;
int s[N], f[M];//s表示可以拿的石子数， f为SG函数值

int sg(int x) {//计算x局面下的sg函数
    if (f[x] != -1) {//该局面已经被算过
        return f[x];
    }
    //接下来计算x局面下接下来能到达的局面
    unordered_set<int> S;
    for (int i = 0; i < m; i++) {//枚举可选石子堆的石子数
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));//如果当前局面下的石子数可以取到当前堆下的石子数，则DFS直到不能取
    }
    //判断集合中不存在的最小自然数是多少，得到SG值   
    for (int i = 0; ; i++) {
        if (!S.count(i)) {
            return f[x] = i;
        }
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) scanf("%d", &s[i]);
    cin >> n;

    memset(f, -1, sizeof f);
    int res = 0;//存储异或后sg的值
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= sg(x);//异或初始石子的sg值便可根据NIM游戏定理预测必胜或者必败态
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}