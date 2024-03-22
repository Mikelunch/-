[//]: # (打卡模板，上面预览按钮可以展示预览效果 ^^)
# ~~"爸"数码~~ 八数码BFS应用
薇妹镇楼
![维尔利特.jpg](https://cdn.acwing.com/media/article/image/2024/03/21/352015_eb925604e7-维尔利特.jpg)
## 需要解决的问题
### 1 状态如何表示？
我们将二维的数组展出一维字符串形式用以表示状态(相当于树搜中的顶点),对应用哈希表存储该状态对应初始状态的距离。**所以该地就本质上抽象成了从1号点出发用BFS到n号点的最短距离问题**。1号点是其实字符串，而n号点就是目标的八数码字符串.
### 2状态的如何转移？
该问题就分为**2维数组和一维字符串的转换问题**和**如何得到x点附件位置的字符问题**。
** 2维数组和一维字符的转换关系**可以由如下公式得到：
假设字符串中字符的位置为 Strpos , 对应n X m 维数组，以纵向为x，横向为y的话，其转换公式如下：
++**Strpos = x * n + y % m**++
如下图所示的例子：
![位置关系.jpg](https://cdn.acwing.com/media/article/image/2024/03/22/352015_70f957f1e8-位置关系.jpg) 

### 3如何移动x周围的数字呢
既然得到了字符串对应字符和矩阵坐标之间的关系，同ACWING844及那道微软面试题边可以得出，我们只需要上下左右对应的4个方向矩阵dx[4],dy[4]，配合swap()便可交换对应的字符，做到状态转移。

**综上**，该题关于状态的存储和转移问题边得到了全部的解决，接下来只需套用常规的BFS模板即可解决该问题。该问题的实质还是利用BFS解决图中最短路径问题，只不过顶点换成的字符串，对应距离用哈希表存储，且图是没有给定出来的。后续可能还可以使用dijkstra或者SPFA解决，后续尝试下！

## 全部代码如下
```
#include<iostream>
#include<queue>//BFS用队列来实现
#include<unordered_map>//哈希表实现距离
#include<algorithm>

using namespace std;

int bfs(string start){
    string end = "12345678x";//定义状态转移的最终目标
    queue<string> q;//BFS用队列
    unordered_map<string , int> d;//存储状态的距离
    int dx[4] = {0 , 0 , -1 , 1} , dy[4] = {1 , -1 , 0 , 0}; //控制方向
    //BFS经典操作
    q.push(start);//第一步初始化
    d[start] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int dis = d[t];
        if(t == end) return d[t];
        //状态转移
        int k  = t.find('x');//找到x在字符串中的位置
        int x = k / 3 , y = k % 3;//将x在字符串中的位置转换成矩阵中的坐标
        for(int i = 0 ; i < 4 ;i++){
            int a = x + dx[i] , b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){//移动x没有越界
                swap(t[a * 3 + b] , t[k]);//有矩阵坐标转换回字符串中的位置公式
                if(!d.count(t)){//查询当前哈希表没有发现这个状态的话就加入进去
                    d[t] = dis + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b]  , t[k]);//恢复现场
            }
        }
    }
    return -1;
}

int main(){
    string start;//存储初始转台
    char c[2];
    for(int i = 0 ; i < 9; i++){//因为是矩阵输入 所以这样传递给字符串
        cin >> c;
        start += *c; 
    }
    cout << bfs(start) << endl;
    return 0;
}
```
