/*
线性表作业
链表重排
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 2e4 + 10;
string head_addr; int n;
struct Node {
    string addr, nxt;
    int data;
} a[MAXN], ans[MAXN];
map<string, int> mp;
int id[MAXN];
int num[MAXN], n_cnt;
int main() {
    cin >> head_addr >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].addr >> a[i].data >> a[i].nxt;
        mp[a[i].addr] = i;
    }
    string x = head_addr;
    for(int i = 1; i <= n; i++) {
        id[i] = mp[x];
        x = a[id[i]].nxt;
    }
    int l = 1, r = n;
    while(l <= r) {
        num[++n_cnt] = r;
        num[++n_cnt] = l;
        l++, r--;
    }
    for(int i = 1; i <= n; i++) {
        ans[i].addr = a[id[num[i]]].addr;
        ans[i].data = a[id[num[i]]].data;
        ans[i].nxt = a[id[num[i+1]]].addr;
    }
    ans[n].nxt = "-1";
    for(int i = 1; i <= n; i++)
        cout << ans[i].addr << " " << ans[i].data << " " << ans[i].nxt << endl;
    return 0;
}