[//]: # (打卡模板，上面预览按钮可以展示预览效果 ^^)
# spfa求最短路算法
薇妹镇楼
![维尔利特.jpg](https://cdn.acwing.com/media/article/image/2024/03/14/352015_1d36f21ae1-维尔利特.jpg) 
**适用于：**有负权边的最短路搜索图中。它更像是优化版的朴素Ballman-ford算法，但又实际模板又和bfs很想。这几个算法长的很像，要注意归类整理。
##算法模板：
首先先回顾下ballman-ford算法的模板，看看其中有哪点可以优化。ballman-ford算法模板如下:
```
1.**初始化**：d[1] = 0 , d[其他] = 无穷大
2.for(**迭代k次**){k:题目规定的最多k条边下的1到n的最短距离
    2.1复制上一次迭代的d[]数据到 dp[]中
    for(遍历所有边){
        更新位置距离 d[] = min(d[] , dp[] + w)
    }
}
3.**输出**:d[n]
```
其中，主要是第二重循环中会遍历所有边，而在稠密图中边的数量又很多，在：更新位置距离 d[] = min(d[] , dp[] + w)处，我们可得**只有dp[]减小的情况下，该距离才会被更新到d[]中**，由此我们利用bfs去搜索dp[]下降的这些点，对这些点的d[]进行更新便会减小大量的无效边搜索。
由此，spfa的**核心**便是：**利用bfs算法找到距离减小的点进行更新。**
既然是bfs算法，则自然会用到队列q[]，该算法中q[]用于存储**那些在本次搜索中距离减小的顶点。**
**算法模板如下**
```
1.初始化 d[1] = 0 , d[其他] = 无穷大 q[0] = 1
2.while(队列非空){
    t = 队首弹出元素
    3.for(遍历t顶点的邻接表){
        3.1 更新距离
        3.2 成功更新距离的顶点压入队列
    }
}
4.返回 d[n]

```
**spfa核心代码如下**
```
int spfa(void){
    memset(d , 0x3f , sizeof d); //1.初始化 
    d[1] = 0;
    q.push(1);//压入初始点
    s[1] = true;
    while(q.size()){//2.队列非空 bfs变形模板
        auto t = q.front();
        q.pop();
        s[t] = false;
        for(int i = h[t]; ~i ; i = ne[i]){
            int j = e[i];
            if(d[j] > d[t] + w[i]){//更新距离
                d[j] = d[t] + w[i];
                if(!s[j]){
                    q.push(j);//只要距离成功更新，说明d[t]肯定是减小的
                    s[j] = true;
                }
            }
        }
    }
    return d[n];
}
```
## 2点疑问
### 1 为什么要使用s[]记录该点的使用情况？
**为了节省运算时间**。因为在题目中可能出现卡数据情况，即一种情况是环的存在可能导致一次更新中同一点多次进入队列中，而外层循环在队列非空的情况会一直进行，这将导致同一点多次无效的搜索，因此，添加s[]来提高速度，节省时间。详细解释也可见 [https://www.acwing.com/problem/content/discussion/content/3136/](http://) 
### 2 于ballman-ford算法的异同
还是有很多区别的。**1.应用场景有区别**,bf算法更多是最多走k次路径下的最短距离，而sfpa是求带负权边的最短距离。**2.存储图的格式不一样**，bf算法一般用结构存储所有边的信息，而spfa算法用临界便存储整个图的信息。
也有一点相同 **均对负环敏感**，挖坑ACWING852。bf算法还是比spfa算法队负环更耐久一点，详细可见AWCING853

## 全部代码如下
```
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100086;
int h[N] , e[N] , ne[N] , w[N], idx;
queue<int> q;
bool s[N];
int d[N];
int n , m;

void init(void){
    memset(h , -1 ,sizeof h);
    idx = 0;
}

void add(int a , int b , int c){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx , w[idx] = c , idx++;
} 

int spfa(void){
    memset(d , 0x3f , sizeof d); //1.初始化 
    d[1] = 0;
    q.push(1);//压入初始点
    s[1] = true;
    while(q.size()){//2.队列非空 bfs变形模板
        auto t = q.front();
        q.pop();
        s[t] = false;
        for(int i = h[t]; ~i ; i = ne[i]){
            int j = e[i];
            if(d[j] > d[t] + w[i]){//更新距离
                d[j] = d[t] + w[i];
                if(!s[j]){
                    q.push(j);//只要距离成功更新，说明d[t]肯定是减小的
                    s[j] = true;
                }
            }
        }
    }
    return d[n];
}

int main(){
    cin >> n >> m;
    init();
    for(int i = 0 ; i < m ; i++){
        int a, b , c;
        scanf("%d %d %d" , &a , &b ,&c);
        add(a , b ,c);
    }
    int t = spfa();
    if(d[n] == 0x3f3f3f3f) printf("impossible");
    else printf("%d" , d[n]);
    
    return 0;
}
```
