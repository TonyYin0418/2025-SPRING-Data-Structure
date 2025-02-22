/*
绪论作业
LeetCode9—回文数
*/

#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return 0;
    int y = 0, x_copy = x;
    while(x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y == x_copy;
}
int main() {
    freopen("in.txt", "r", stdin);
    int x; cin >> x;
    cout << isPalindrome(x) << endl;
    return 0;
}