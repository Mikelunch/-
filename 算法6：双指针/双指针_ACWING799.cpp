#include<iostream>
using namespace std;

const int N = 1e6;
int nums[N], cnt[N]; //nums是输入数组 cnt是计数数组用于记录每个nums中数字出现的次数

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    int len = 0;
    for (int i = 0, j = 0; i < n; i++) { //核心
        cnt[nums[i]]++; //标记该段中每个数出现的次数
        while (cnt[nums[i]] > 1) { //说明[j,i]中有重复的数
            cnt[nums[j]]--;//将该段出现的数字的次数--为下一段计数做准备
            j++;//j向i方向滑动 并最终会停在i位置
        }
        len = len > (i - j + 1) ? len : (i - j + 1);
    }

    cout << len << endl;

    return 0;
}