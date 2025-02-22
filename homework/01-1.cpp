/*
绪论作业
POJ3048-最大因子
*/

#include <iostream>

using namespace std;

const int MAXN = 5e3, MAXA = 2e4;
int is_prime[MAXA + 10], prime[MAXA + 10], cnt;
int n;
int main() {
    freopen("in.txt", "r", stdin);
    for(int i = 2; i < MAXA; i++) {
        if(!is_prime[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= MAXA; j++) {
            is_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    int max_fac = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        for(int j = cnt; j >= 1; j--) {
            if(x % prime[j] == 0) {
                if(prime[j] > max_fac) {
                    max_fac = prime[j];
                    ans = x;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}