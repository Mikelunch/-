//该题的关键就是在于维护并查集中的元素到根节点的长度
#include<iostream>
using namespace std;


const int N = 2e5;
int p[N], d[N];
int cnt;

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);//暂存根节点
        d[x] += d[p[x]]; //累加到父节点的距离
        p[x] = t;//更新成根节点 执行路径压缩
    }
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i; //初始化

    while (m--) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        int pa = find(a), pb = find(b);

        if (a > n || b > n) {//非法语句
            //cout << m << ' ' << a << ' '<< b << endl;
            cnt++;
            continue;
        }

        if (t == 1) {//判断是否为同一物种
            if (pa != pb) {//不在同一个树中 并入同一树中 默认为真话
                p[pa] = pb;
                d[pa] = d[b] - d[a];
            }
            else {//在同一个树中
                if ((d[a] - d[b]) % 3) {
                    cnt++;//d[a] % 3 != d[b] % 3
                    //cout << m << ' ' << a << ' '<< b << endl;
                }
            }
        }
        else {//判断吃和被吃的关系
            if (pa != pb) {//不在同一个树中 并入同一树中 默认为真话
                p[pa] = pb;
                d[pa] = d[b] + 1 - d[a];//子代吃父代
            }
            else {//在同一个树中
                if ((d[a] - d[b] - 1) % 3) {//关系错误 
                    cout << d[a] << ' ' << d[b] << endl;
                    cnt++;
                    //cout << m << ' ' << a << ' '<< b << endl;
                }
            }
        }
    }

    printf("%d", cnt);

    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7529886/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。