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

作者：ConstantZ
链接：https://www.acwing.com/activity/content/code/content/8147864/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
