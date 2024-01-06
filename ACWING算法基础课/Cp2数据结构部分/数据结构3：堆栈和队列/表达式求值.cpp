#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

stack<int> num; //����������
stack<int> op; //������

void eval() {
    auto b = num.top(); num.pop();//��ȡ�������ұߵ��� ��Ϊ��������ջ��
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
    unordered_map<char, int> pr{ {'+' , 1} , {'-' , 1} , {'*' , 2} , {'/' , 2} };//�������ȼ�
    string cmds;
    cin >> cmds;
    for (int i = 0; i < cmds.size(); i++) {
        char s = cmds[i];
        if (isnums(s)) {//���������
            int x = 0, j = i;
            for (; isnums(cmds[j]) && j < cmds.size(); j++) {
                x = x * 10 + cmds[j] - '0';
            }
            i = j - 1;
            num.push(x);//��ת���õ�����ѹ������ջ
        }
        else if (s == '(') op.push(s); //����������ѹ��ջ Ϊ������������׼��
        else if (s == ')') {//���� ) ����Ҫ�������� ֱ��������ǰѹ��ջ�� ( Ϊֹ
            while (op.top() != '(') eval();//ִ������
            op.pop();//������ɽ� ( ���� ���� ()�ͼ������
        }
        else { // + - * / ����һ��������
            while (op.size() && pr[op.top()] >= pr[s]) eval();//�����ǰ s ����Ĳ��������������ȼ�С�ڸ��ڵ�����ȼ� ���������� ֱ�����ڵ������������ȼ�С���ӽڵ��
            op.push(s);//���ڵ����������ȼ�С�� s �����������
        }
    }
    while (op.size()) eval(); //���ϲ����ڵ�����������ӽڵ��ֵ �õ������
    printf("%d", num.top());
    return 0;
}
