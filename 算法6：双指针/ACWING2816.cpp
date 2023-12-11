#include<iostream>
using namespace std;

const int N = 1e6;
int a[N], b[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    /*
    int j = 0, flag = 0;
    for(int i = 0; i < n ; i++){
        for(; j < m; j++){
            if(a[i] == b[j]){
                //cout << a[i] << " " << b[j] << endl;
                j++; //判定成功后j也必须向前移动 防止出现重复数字
                flag++;
                break;
            }
        }
    }

    if(flag == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    */
    /*
    //优雅的化简上述代码
    int i = 0;
    for(int j = 0 ; j < m ; j++){
        if(a[i] == b[j] && i < n) i++; //若是子序列则一定是依次出现的 即找到了第一个数才能去找第二个数
    }
    if(i == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    */

    //附上一种y总做法
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) i++;
        j++;
    }
    if (i == n) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}