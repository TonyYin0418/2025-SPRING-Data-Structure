/*
第一周练习
P2242 公路维修问题
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e4;
int n, m, a[MAXN];
int d[MAXN];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; 
        d[i - 1] = a[i] - a[i - 1];
    }
    sort(d + 1, d + n);
    int ans = 0;
    for(int i = 1; i + m - 1 < n; i++) {
        ans += d[i];
    }
    cout << ans + m << endl;
    return 0;
}