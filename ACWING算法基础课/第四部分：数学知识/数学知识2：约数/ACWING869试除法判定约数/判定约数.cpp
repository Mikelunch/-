#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;

vector<int> get_divsion(int num) {
    vector<int> res;
    for (int i = 1; i <= num / i; i++) {
        if (num % i == 0) {
            res.push_back(i);
            if (i != num / i) res.push_back(num / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin >> n;
    while (n--) {
        int num;
        scanf("%d", &num);
        vector<int> res = get_divsion(num);
        for (auto t : res) printf("%d ", t);
        printf("\n");
    }
    return 0;
}