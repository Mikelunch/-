#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

stack<int> num; //操作的数字
stack<int> op; //操作符

void eval() {
    auto b = num.top(); num.pop();//先取操作符右边的数 因为他是最后进栈的
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int res;
    if (c == '+') res = a + b;
    if (c == '-') res = a - b;
    if (c == '*') res = a * b;
    if (c == '/') res = a / b;
    num.push(res);
}

bool isnums(char x) {
    return x >= '0' && x <= '9';
}

int main() {
    unordered_map<char, int> pr{ {'+' , 1} , {'-' , 1} , {'*' , 2} , {'/' , 2} };//定义优先级
    string cmds;
    cin >> cmds;
    for (int i = 0; i < cmds.size(); i++) {
        char s = cmds[i];
        if (isnums(s)) {//如果是数字
            int x = 0, j = i;
            for (; isnums(cmds[j]) && j < cmds.size(); j++) {
                x = x * 10 + cmds[j] - '0';
            }
            i = j - 1;
            num.push(x);//将转换好的数字压入数字栈
        }
        else if (s == '(') op.push(s); //遇见左括号压入栈 为遇见右括号做准备
        else if (s == ')') {//遇见 ) 则需要立即计算 直到遇见提前压入栈的 ( 为止
            while (op.top() != '(') eval();//执行运算
            op.pop();//计算完成将 ( 弹出 整个 ()就计算完成
        }
        else { // + - * / 这类一般的运算符
            while (op.size() && pr[op.top()] >= pr[s]) eval();//如果当前 s 代表的操作符的运算优先级小于父节点的优先级 则向上运算 直到父节点的运算符的优先级小于子节点的
            op.push(s);//父节点的运算符优先级小于 s 则继续向下走
        }
    }
    while (op.size()) eval(); //最后合并根节点的左右两个子节点的值 得到最后结果
    printf("%d", num.top());
    return 0;
}
