/*
线性表作业
LeetCode1——两数之和
*/

#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;
int n, a[MAXN], target;

int main() {
    freopen("in.txt", "r", stdin);
    while(cin >> a[n]) n++;
    n--;
    target = a[n];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == target) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}