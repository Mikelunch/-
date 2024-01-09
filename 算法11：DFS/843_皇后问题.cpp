#include<iostream>
using namespace std;

const int N = 10;
int p[N];//显示用数组
bool st[N];//记录每个数的使用情况
int n;

void dfs(int u) {
    if (u == n) {//满足深度则输出并返回
        for (int i = 0; i < n; i++) printf("%d ", p[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {//没由达到深度条件则继续向下搜索
        if (!st[i]) {//该数字并没有被使用
            p[u] = i;//该层使用这个数字
            st[i] = true;//记录该位上的数字已被使用下一层不能使用
            dfs(u + 1);//向下一层搜索
            st[i] = false;//返回时要进行回溯并恢复现场
        }
    }
}

int main() {

    cin >> n;

    dfs(0);

    return 0;

}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7589678/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。