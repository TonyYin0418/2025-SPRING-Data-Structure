/*
第二周练习
洛谷P1160 队列安排
*/
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10, MAXV = 1e5 + 10;

int n, m;
int a[MAXN], Left[MAXN], Right[MAXN], cnt, head;
int id[MAXV];
inline void add_left(int x, int y) {
    int new_node = ++cnt;
    a[new_node] = y, id[y] = new_node;
    int x_id = id[x];
    if(head == x_id) head = new_node;
    Left[new_node] = Left[x_id];
    Right[Left[x_id]] = new_node;
    Left[x_id] = new_node;
    Right[new_node] = x_id;
}
inline void add_right(int x, int y) {
    int new_node = ++cnt;
    a[new_node] = y, id[y] = new_node;
    int x_id = id[x];
    
    Right[new_node] = Right[x_id];
    Left[Right[x_id]] = new_node;
    Right[x_id] = new_node;
    Left[new_node] = x_id;
}
inline void del(int x) {
    if(!id[x]) return ;
    int x_id = id[x];
    Right[Left[x_id]] = Right[x_id];
    Left[Right[x_id]] = Left[x_id];
    if(head == x_id) head = Right[x_id];
    id[x] = 0;
}
inline void print() {
    int x = head;
    while(x) {
        cout << a[x] << ' ';
        x = Right[x];
    }
    cout << endl;

}
int main() {
    cin >> n;
    a[++cnt] = 1, id[1] = head = cnt;
    for(int i = 2; i <= n; i++) {
        int opt, x;
        cin >> x >> opt;
        if(opt == 0) { // left
            add_left(x, i);
        } else { // right
            add_right(x, i);
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        del(x);
    }
    print();
    return 0;
}