/*
第一周练习
洛谷P2240 【深基12.例1】部分背包问题
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 110, MAXT = 1010;
int n, T;
struct Node {
    int m, v;
} a[MAXN];
bool cmp(Node A, Node B) {
    return A.v/(double)A.m > B.v/(double)B.m;
}
int main() {
    cin >> n >> T;
    for(int i = 1; i <= n; i++) cin >> a[i].m >> a[i].v;
    sort(a + 1, a + n + 1, cmp);
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        if(T >= a[i].m) ans += a[i].v, T -= a[i].m;
        else {
            ans += T * a[i].v / (double)a[i].m;
            break;
        }
    }
    printf("%.2lf", ans);
    return 0;
}