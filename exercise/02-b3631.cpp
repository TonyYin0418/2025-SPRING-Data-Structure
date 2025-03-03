/*
第二周练习
洛谷B3631 单向链表
*/
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10, MAXV = 1e6 + 10;

int Q;
int a[MAXN], nxt[MAXN], cnt;
int id[MAXV];
inline void add(int x, int y) {
    int x_id = id[x];
    a[++cnt] = y, id[y] = cnt;
    nxt[cnt] = nxt[x_id];
    nxt[x_id] = cnt;
}
inline int query(int x) {
    int x_id = id[x];
    return a[nxt[x_id]];
}
inline void del(int x) {
    int x_id = id[x];
    nxt[x_id] = nxt[nxt[x_id]];
}
int main() {
    a[++cnt] = 1, id[1] = cnt;
    cin >> Q;
    while(Q--) {

        int opt, x, y;
        cin >> opt >> x;
        if(opt == 1) {
            cin >> y;
            add(x, y);
        } else if(opt == 2) {
            cout << query(x) << endl;
        } else if(opt == 3) {
            del(x);
        }
    }
    return 0;
}