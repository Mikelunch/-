#include<iostream>
using namespace std;

const int N = 1e7;
char s[N], p[N]; //比较字符串 模板串
int ne[N];

int main() {
    int n, m;
    cin >> n >> p + 1 >> m >> s + 1;//为避免边界问题 统一从下标1开始输入数据

    //ne数组求解问题： ne[i]:i长度下的模板子串的前缀和比较子串的后缀最长的相同部分 其本质就是自己和自己比较
    for (int i = 2, len = 0; i <= n; i++) { //因为下标是1开始的 所以长度为0下没有子串 长度为1的默认没有前后最
        while (len && p[i] != p[len + 1]) len = ne[len]; //往往这一部分会在 下一部分if执行后才能执行      
        if (p[i] == p[len + 1]) len++;
        ne[i] = len;
    }
    //匹配问题
    for (int i = 1, len = 0; i <= m; i++) {
        while (len && s[i] != p[len + 1]) { //部分匹配成功 在len + 1处模板串和比较串开始不相同了
            len = ne[len]; //从后缀长度为ne[len]处重新开始比较
            //因为前面的比较结果可以得出比较子串的ne[len]部分后缀和模板串的ne[len]部分前缀相同
           //因此，直接比较比较子串后面和模板子串ne[len]开始的后面部分是否成功即可
        }
        if (s[i] == p[len + 1]) len++;//如果当前长度下的子串匹配 长度再变长
        if (len == n) {//匹配成功 输出想要的结果即可
            cout << i - n << " ";
            len = ne[len]; //为防止比较字符串出现不止一个符合要求的模板串
        }
    }

    //for(int i = 0; i <= n; i++) cout << ne[i] << " ";
    return 0;
}

作者：ConstantZ
链接：https ://www.acwing.com/activity/content/code/content/7506705/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。