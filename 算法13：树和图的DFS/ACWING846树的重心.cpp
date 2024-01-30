#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 2e5, M = 2 * N;
int h[N], e[M], ne[M], idx, n;//单链表形式存储
bool st[N];//运用记录是否重复遍历 该题一个节点只遍历一次
int ans = N;//输出答案

void init() {//链表初始化
    memset(h, -1, sizeof h);
}

void add(int a, int b) {//添加有向图
    e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}

int dfs(int u) {//深度搜索 返回该节点为根节点下子连通块的个数
    st[u] = true;//首先标记该节点使用过了
    int sum = 1, res = 0;//sum用于记录u节点为根节点下子连通块的个数(自己也算),res用于记录当前的最小结果
    for (int i = h[u]; i != -1; i = ne[i]) {//向下遍历链表
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = res > s ? res : s;//存储当前层的最小值
            sum += s;
        }
    }
    res = res > (n - sum) ? res : (n - sum);//比较已该节点为根节点时该节点向上的连通块的最大值
    ans = ans < res ? ans : res;//存储目前的最小结果
    return sum;

}

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);//注意 这里是用有向图双向连接建立无向图
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
