/*
线性表作业
HDU1412—集合并集运算
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e4 + 10;
int n, m, a[MAXN];
int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n + m; i++) cin >> a[i];
    sort(a, a + n + m);
    int pos = unique(a, a + n + m) - a;
    for(int i = 0; i < pos; i++) cout << a[i] << " "; cout << endl;
    return 0;
}