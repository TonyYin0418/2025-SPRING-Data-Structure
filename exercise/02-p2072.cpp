/*
第二周练习
洛谷P2072 宗教问题
*/
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1010, MAXM = 30;

int n, m, k;
int v[MAXN], flag[MAXM];
int f[MAXN];
inline void init_flag() {
    for(int i = 1; i <= m; i++) flag[i] = 0;
}
int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> v[i];
    int cnt = 0, ans1 = 1;
    for(int i = 1; i <= n; i++) {
        if(!flag[v[i]]) {
            flag[v[i]] = 1;
            cnt++;
            if(cnt > k) {
                ans1++;
                for(int j = 1; j <= m; j++) flag[j] = 0;
                flag[v[i]] = 1;
                cnt = 1;
            }
        }
    }
    // f[i]表示前i个人 危险值最小值
    memset(f, 0x3f, sizeof(f));
    f[0] = 0, f[1] = 1; 
    for(int i = 2; i <= n; i++) {
        init_flag(); cnt = 0;
        for(int j = i; j >= 1; j--) {
            if(!flag[v[j]]) {
                flag[v[j]] = 1;
                cnt++;
            }
            if(cnt > k) break;
            f[i] = min(f[i], f[j - 1] + cnt);
        }
    }
    cout << ans1 << endl << f[n] << endl;
    return 0;
}