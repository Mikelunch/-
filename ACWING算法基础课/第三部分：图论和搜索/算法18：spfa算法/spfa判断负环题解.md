[//]: # (打卡模板，上面预览按钮可以展示预览效果 ^^)
# spfa判断负环
薇妹镇楼
![维尔利特.jpg](https://cdn.acwing.com/media/article/image/2024/03/14/352015_8f0b0600e2-维尔利特.jpg) 
## 算法模板
同spfa寻找最短距离相同，只是加入一个统计每个顶点走过的边的数组cnt[]。
算法的核心代码如下：同普通的spfa算法几乎一致
```
bool spfa(void){
    for(int i = 1; i <= n ; i++){
        s[i] = true;
        q.push(i);
    }
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        s[t] = false;
        for(int i = h[t]; ~i ; i = ne[i]){
            int j = e[i];
            if(d[j] > d[t] + w[i]){
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1; //核心判断思路
                if(cnt[j] >= n) return true;
                if(!s[j]){
                    q.push(j);
                    s[j] = true;
                }
            }
        }
    }
    return false;
}
```
**核心的判断原理**:即抽屉原理，同ballman-ford算法对负环敏感的原因一样。只要一个图中存在环，且这个环在最小路径上，则其走过的边的数量一定大于或者点数。
如下图所示：
![负环.jpg](https://cdn.acwing.com/media/article/image/2024/03/14/352015_b13dd7fae1-负环.jpg) 
所以实际上，**如果存在负环，普通spfa算法是出不来去环的。由ACWING851的代码验证。数据如下图所示
![输入.png](https://cdn.acwing.com/media/article/image/2024/03/14/352015_1d11631fe2-输入.png) 
结果如下图所示：
![结果.png](https://cdn.acwing.com/media/article/image/2024/03/14/352015_2571e566e2-结果.png) 
综上，**只要那一个数组来记录更新过的点的目前的累计的变数便可判断是否由负环存在。**这就是spfa判断负环的核心思路。

## 整体代码如下
```
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100086;
int h[N] , e[N] , ne[N] , w[N], idx;
queue<int> q;
bool s[N];
int d[N] , cnt[N];
int n , m;

void init(void){
    memset(h , -1 ,sizeof h);
    idx = 0;
}

void add(int a , int b , int c){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx , w[idx] = c , idx++;
} 

bool spfa(void){
    for(int i = 1; i <= n ; i++){
        s[i] = true;
        q.push(i);
    }
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        s[t] = false;
        for(int i = h[t]; ~i ; i = ne[i]){
            int j = e[i];
            if(d[j] > d[t] + w[i]){
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!s[j]){
                    q.push(j);
                    s[j] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    init();
    for(int i = 0 ; i < m ; i++){
        int a, b , c;
        scanf("%d %d %d" , &a , &b ,&c);
        add(a , b ,c);
    }
    if(spfa()) printf("Yes");
    else printf("No");
    
    return 0;
}
```
