#include<iostream>
using namespace std;

const int N = 1e6;
int a[N], b[N];
int n, m, x;

int find(int x) {//二分法寻找x在b中的相对下标
    int l = 0, r = m - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main() {

    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    //解法1：二分法直接寻找答案
    /*
    for(int i= 0; i < n; i++){
        int b_pos  = find(x - a[i]);
        if(b[b_pos] == x - a[i]){
            cout << i  << " " << b_pos  << endl;
            break;
        }
    }
    */

    //暴力做法 会超时
    /*
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(a[i] + b[j] == x) {
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    */

    //解法2：y总做法

    for (int i = 0, j = m - 1; i < n; i++) { //i j 都是单方向的 所以从单调性入手这类问题
        if (x - a[i] > b[m - 1]) continue;
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (a[i] + b[j] == x) {
            printf("%d %d\n", i, j);
            break;
        }
    }

    return 0;
}