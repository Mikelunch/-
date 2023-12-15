#include<iostream>
using namespace std;

const int N = 1e6;
int stk[N];//单调栈
int tt;//栈顶指针

void init() {
    tt = 0;
}

void push(int x) { //压栈
    stk[++tt] = x;
}

int pop() { //弹栈
    return stk[tt--];
}

bool isempty() { //判定空
    return tt == 0;
}

int main() {
    int n;
    scanf("%d", &n);
    init(); //初始化单调栈
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        while (stk[tt] >= num && !isempty()) { //单调栈顾名思义是满足某一性质的栈 本题便是满足单调递增的栈
            pop();                          //如果栈内是单调递增排列 如果栈顶的数>=输入数，则当前的栈顶是用永远不会被用到的
        }                                   //因为后续的数只会找到当前输入的数作为满足条件的解，所以可以通过弹栈找到符合条件的数作为新的栈顶
        if (!isempty()) printf("%d ", stk[tt]); //非空说明找到了符合条件的数
        else printf("-1 ");
        push(num);
        //调试用 显示当前栈中内容
        //cout << "第" << i << "次循环中栈内容" << endl;
        //for(int j = 0; j <= tt; j++) cout << stk[j] << " ";
        //cout << endl;
    }

    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7503120/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。