/*
第二周练习
洛谷P2031 脑力达人之分割字串
*/
#include <iostream>

using namespace std;

const int MAXN = 510, MAXLEN = 310;

string s, a[MAXN];
int n, len[MAXN];
int dp[MAXLEN]; // dp[i]: 以i为间断点 & 结尾 的答案
int main() {
    cin >> s >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        len[i] = a[i].length();
    }
    int s_len = s.length();
    dp[0] = 0;
    for(int i = 0; i < s_len; i++) {
        // 枚举上一个间断点，或继承i-1的答案
        if(i) dp[i] = dp[i - 1];
        for(int j = 1; j <= n; j++) if(i + 1 >= len[j]) {
            if(s.substr(i-len[j]+1, len[j]) != a[j]) continue;
            if(i + 1 == len[j]) {
                dp[i] = max(1, dp[i]);
            } else {
                dp[i] = max(dp[i - len[j]] + 1, dp[i]);
            }
        }
    }
    cout << dp[s_len - 1] << endl;
    return 0;
}