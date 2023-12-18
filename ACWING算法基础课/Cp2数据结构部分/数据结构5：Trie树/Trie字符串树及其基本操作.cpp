#include<iostream>
using namespace std;

const int N = 1e7;
int son[N][26];//trie数中每个节点的子节点 题中保证了输入字符总长度不超过N，即最多N个节点
int cnt[N];//终节点 该节点表示一串字符的末尾
int idx;//内存分配指针 调度 son数组使用 注意 下标为0即为根节点也是空节点
char str[N];//输入的字符串

void insertTrie(char str[]) {
    int p = 0;//默认指向根节点
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a'; //a - z映射到 0-25
        if (!son[p][u]) son[p][u] = ++idx;//当前这个节点没有这个字符对应的子节点，便创建出来
        p = son[p][u]; //p节点走到子节点
    }
    cnt[p]++; //标记尾节点
}

int quiry(char str[]) {
    int p = 0;//默认从根节点开始向下查找
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0; //未找到子节点即没有这个字符串
        p = son[p][u];//一直向下查找匹配
    }
    return cnt[p]; //查找到该字符串 返回尾节点位置
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'I') {
            cin >> str;
            insertTrie(str);
        }
        if (cmd == 'Q') {
            cin >> str;
            cout << quiry(str) << endl;
        }
    }
    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7517726/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。